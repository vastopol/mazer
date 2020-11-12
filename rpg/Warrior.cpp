#include <iostream>
#include <string>

#include "Character.h"
#include "Warrior.h"

using namespace std;

    // private:
    // string allegiance;
    
    //public:
 
    Warrior::Warrior( const string &name, double health, double attackStrength, const string &tribe)
       :Character(WARRIOR, name, health, attackStrength), allegiance(tribe)
    {}
 
//================================================================================================================   
    /*
    void Warrior::attack(Character &cname)
    {
        if(cname.getType() == WARRIOR)
        {
           Warrior &opp = dynamic_cast<Warrior &>(cname);
            if(opp.allegiance == this->allegiance)
            {
                cout << "Warrior " << this->name << " does not attack Warrior " << cname.getName() << "." << endl;
                cout << "They share an allegiance with " << opp.allegiance << "." << endl;
                
                return;
            }
        }
        
       double damage = 0;
       damage = (this->health / MAX_HEALTH) * (this->attackStrength) ;
       
       cname.setHealth(cname.getHealth() - damage);
        
        cout << "Warrior " << this->name << " attacks " << cname.getName() << " --- SLASH!!" << endl;
        cout << cname.getName() << " takes " << damage << " damage."  << endl;
    
        return;


    }
    */
    
    // Warrior

// Stores the warrior's allegiance as a string.

// The warrior does not attack warriors that have the same allegiance.

//The damage done by the warrior is the percentage of the warrior's health remaining (health / MAX_HEALTH) multiplied by the warrior's attack strength.
    //Warrior &opp = dynamic_cast<Warrior &>(opponent);
//=========================================================================================================
    
    void Warrior::attack(Character &opponent) {
    if (!opponent.isAlive()) {
        return;
    }
    if (opponent.getType() == WARRIOR) {
        Warrior &opp = dynamic_cast<Warrior &>(opponent);
        if (opp.allegiance == allegiance) {
            cout << "Warrior " << name << " does not attack Warrior "
                << opp.name << ".\nThey share an allegiance with "
                << allegiance << "." << endl;\
            return;
        }
    }
    double damageDone = (health / MAX_HEALTH) * attackStrength;
    opponent.setHealth(opponent.getHealth() - damageDone);
    cout << "Warrior " << name << " attacks " << opponent.getName()
        << " --- SLASH!!\n";
    if (opponent.isAlive()) {
        cout << opponent.getName() << " takes " << damageDone << " damage." << endl;
    } else {
        cout << opponent.getName() << " is dead!" << endl;
    }
}