#ifndef __WIZARD_H__
#define __WIZARD_H__

#include "Character.h"

#include <iostream>
#include <string>

using namespace std;

class Wizard : public Character
{

    private:
    int rank;
    
    public:
    //Wizard();
    Wizard( const string &name, double health, double attackStrength,  int level );
    void attack(Character &cname);


};


#endif // __WIZARD_H__