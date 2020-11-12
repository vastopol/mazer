#include <iostream>
#include <string>

#include "Character.h"

using namespace std;


/*STUFFS

enum CharType {WARRIOR, ELF, WIZARD};

const double MAX_HEALTH = 100.0;

class Character {
 protected:
    CharType type;
    string name;
    double health;
    double attackStrength;
*/

 //public:
 
 //no default constructor either
     
     Character::Character(CharType type, const string &name, double health, double attackStrength)
         :type(type), name(name), health(health), attackStrength(attackStrength)
     {}
     
     CharType Character::getType() const
     {
      return this->type;
     }
     
     const string & Character::getName() const
     {
        return this->name; 
     }
     
     /* Returns the whole number of the health value (static_cast to int). */
     int Character::getHealth() const
     {
         return static_cast<int>(health);
     }
     
     void Character::setHealth(double h)
     {
         this->health = h;
         return;
     }
     
     /* Returns true if getHealth() returns an integer greater than 0, otherwise false */
     bool Character::isAlive() const
     {
         if(this->getHealth() > 0)
         {
            return true;
         }
         return false;
     }
     
 //no virtual void attack definition???