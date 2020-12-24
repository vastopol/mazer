#ifndef __WIZARD_H__
#define __WIZARD_H__

#include <iostream>
#include <string>

#include "Character.h"

using namespace std;

class Wizard : public Character {
private:
  int rank;

public:
  Wizard(const string &name, double health, double attackStrength, int level);
  void attack(Character &cname);
};

#endif