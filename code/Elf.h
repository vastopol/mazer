#ifndef __ELF_H__
#define __ELF_H__

#include <iostream>
#include <string>

#include "Character.h"

using namespace std;

class Elf : public Character {
private:
  string famName;

public:
  Elf(const string &name, double health, double attackStrength,
      const string &family);
  void attack(Character &cname);
};

#endif