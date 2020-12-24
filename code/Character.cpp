#include <iostream>
#include <string>

#include "Character.h"

using namespace std;

Character::Character(CharType type, const string &name, double health,
                     double attackStrength)
    : type(type), name(name), health(health), attackStrength(attackStrength) {}

CharType Character::getType() const { return this->type; }

const string &Character::getName() const { return this->name; }

int Character::getHealth() const { return static_cast<int>(health); }

void Character::setHealth(double h) {
  this->health = h;
  return;
}

bool Character::isAlive() const {
  if (this->getHealth() > 0) {
    return true;
  }
  return false;
}
