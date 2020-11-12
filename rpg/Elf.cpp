#include <iostream>
#include <string>

#include "Character.h"
#include "Elf.h"

using namespace std;

    // private:
    // string famName;
    
    // public:
    Elf::Elf(const string &name, double health, double attackStrength, const string &family)
        :Character(ELF, name, health, attackStrength), famName(family)
    {}
/*    
    void Elf::attack(Character &cname)
    {
        if(cname.getType() == ELF)
        {
           Elf &opp = dynamic_cast<Elf &>(cname);
            if(opp.famName == this->famName)
            {
                
                cout << "Elf " << this->name << " does not attack Elf " << cname.getName() << "." << endl;
                cout << "They are both members of the " << opp.famName << " family." << endl;
                
                return;
            }
        }
        

       double damage = 0;
       damage = (this->health / MAX_HEALTH) * (this->attackStrength) ;
       
       cname.setHealth(cname.getHealth() - damage);
        
        cout << "Elf " << this->name << " shoots an arrow at " << cname.getName() << " --- TWANG!!" << endl;
        cout << cname.getName() << " takes " << damage << " damage."  << endl;
    
        
        return;
    }
*/    
    // Stores the elf's family name as a string.

// The elf does not attack elf's from its own family.

// The damage done by the elf is the percentage of the elf's health remaining (health / MAX_HEALTH) multiplied by the elf's attack strength.

    // CharType type;
    // string name;
    // double health;
    // double attackStrength;
//======================================================================================================

 void Elf::attack(Character &opponent) {
    if (!opponent.isAlive()) {
        return;
    }
    if (opponent.getType() == ELF) {
        Elf &opp = dynamic_cast<Elf &>(opponent);
        if (opp.famName == famName) {
            cout << "Elf " << name << " does not attack Elf "
                << opp.name << ".\nThey are both members of the "
                << famName << " family." << endl;\
            return;
        }
    }
    double damageDone = (health / MAX_HEALTH) * attackStrength;
    opponent.setHealth(opponent.getHealth() - damageDone);
        cout << "Elf " << this->name << " shoots an arrow at " << opponent.getName() << " --- TWANG!!" << endl;

    if (opponent.isAlive()) {
        cout << opponent.getName() << " takes " << damageDone << " damage." << endl;
    } else {
        cout << opponent.getName() << " is dead!" << endl;
    }
}
