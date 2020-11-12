#ifndef __CHARACTER_H__
#define __CHARACTER_H__

#include <iostream>
#include <string>

using namespace std;


enum CharType {WARRIOR, ELF, WIZARD};

const double MAX_HEALTH = 100.0;

class Character {
 protected:
    CharType type;
    string name;
    double health;
    double attackStrength;

 public:
     Character(CharType type, const string &name, double health, double attackStrength);
     CharType getType() const;
     const string & getName() const;
     /* Returns the whole number of the health value (static_cast to int). */
     int getHealth() const;
     void setHealth(double h);
     /* Returns true if getHealth() returns an integer greater than 0, otherwise false */
     bool isAlive() const;
     virtual void attack(Character &) = 0;
 };
 
#endif // __CHARACTER_H__