#ifndef __ELF_H__
#define __ELF_H__

#include "Character.h"

#include <iostream>
#include <string>

using namespace std;

class Elf : public Character
{
    private:
    string famName;
    
    public:
    //Elf();
    Elf( const string &name, double health, double attackStrength, const string &family);
    void attack(Character &cname);
    

};


#endif // __ELF_H__