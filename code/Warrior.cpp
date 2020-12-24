#include <iostream>
#include <string>

#include "Character.h"
#include "Warrior.h"

using namespace std;

// Stores the warrior's allegiance as a string.
// The warrior does not attack warriors that have the same allegiance.
// The damage done by the warrior is the percentage of the warrior's health
// remaining (health / MAX_HEALTH) multiplied by the warrior's attack strength.

Warrior::Warrior(const string &name, double health, double attackStrength,
                 const string &tribe)
    : Character(WARRIOR, name, health, attackStrength), allegiance(tribe) {}

void Warrior::attack(Character &opponent) {
  if (!opponent.isAlive()) {
    return;
  }
  if (opponent.getType() == WARRIOR) {
    Warrior &opp = dynamic_cast<Warrior &>(opponent);
    if (opp.allegiance == allegiance) {
      cout << "Warrior " << name << " does not attack Warrior " << opp.name
           << ".\nThey share an allegiance with " << allegiance << "." << endl;
      return;
    }
  }
  double damageDone = (health / MAX_HEALTH) * attackStrength;
  opponent.setHealth(opponent.getHealth() - damageDone);
  cout << "Warrior " << name << " attacks " << opponent.getName()
       << " --- SLASH!!\n";
  if (opponent.isAlive()) {
    cout << opponent.getName() << " takes " << damageDone << " damage." << endl;
  } else {
    cout << opponent.getName() << " is dead!" << endl;
  }
}