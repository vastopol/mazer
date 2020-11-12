#ifndef __WARRIOR_H__
#define __WARRIOR_H__

#include "Character.h"

#include <iostream>
#include <string>

using namespace std;

class Warrior : public Character
{
    
    private:
    string allegiance;
    
    public:
    //Warrior();
    Warrior( const string &name, double health, double attackStrength, const string &tribe);
    void attack(Character &cname);
    

};


#endif // __WARRIOR_H__