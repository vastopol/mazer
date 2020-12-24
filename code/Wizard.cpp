#include <iostream>
#include <string>

#include "Character.h"
#include "Wizard.h"

using namespace std;

// Stores the wizard's rank as an int.
// When a wizard attacks another wizard, the damage done is the wizard's attack
// strength multiplied by the ratio of the attacking wizard's rank over the
// defending wizard's rank. The damage done to non-wizards is just the attack
// strength. The wizard's health is not taken into consideration.

Wizard::Wizard(const string &name, double health, double attackStrength,
               int level)
    : Character(WIZARD, name, health, attackStrength), rank(level) {}

void Wizard::attack(Character &opponent) {
  double damage = 0;
  if (!opponent.isAlive()) {
    return;
  }
  if (opponent.getType() == WIZARD) {
    Wizard &opp = dynamic_cast<Wizard &>(opponent);
    damage = (this->attackStrength) * (static_cast<double>(this->rank)) /
             (static_cast<double>(opp.rank));

    cout << "Wizard " << this->name << " attacks " << opponent.getName()
         << " --- POOF!!" << endl;
    cout << opponent.getName() << " takes " << damage << " damage." << endl;

    opponent.setHealth(opponent.getHealth() - damage);
    return;
  }

  damage = attackStrength;
  opponent.setHealth(opponent.getHealth() - damage);

  cout << "Wizard " << this->name << " attacks " << opponent.getName()
       << " --- POOF!!" << endl;
  if (opponent.isAlive()) {
    cout << opponent.getName() << " takes " << damage << " damage." << endl;
  } else {
    cout << opponent.getName() << " is dead!" << endl;
  }

  return;
}
