#include <iostream>
#include <list>
#include <ctime>
#include <cstdlib>

#include "Character.h"
#include "Warrior.h"
#include "Elf.h"
#include "Wizard.h"

using namespace std;

int main() 
{
    srand(time(NULL));
        
    list<Character*> team1;
    team1.push_back(new Warrior("Arthur", MAX_HEALTH, 5, "King George"));
    team1.push_back(new Warrior("Jane", MAX_HEALTH, 6, "King George"));
    team1.push_back(new Elf("Raegron", MAX_HEALTH, 4, "Sylvarian"));
    team1.push_back(new Elf("Cereasstar", MAX_HEALTH, 3, "Sylvarian"));
    team1.push_back(new Wizard("Adali", MAX_HEALTH, 5, 8));
    team1.push_back(new Wizard("Vrydore", MAX_HEALTH, 4, 6));
    
    cout << "display team before" << endl;
    for(list<Character*>::iterator it = team1.begin(); it != team1.end(); ++it)
    {
        cout << (*it)->getName() << endl;
    }
    cout << endl;  
    
    string names;
    list<Character*> temp1;
    list<Character*>::iterator ppp = team1.begin();
    cout << "choose order of characters 1-6" << endl;
    cout << "choose character to push back" << endl;
    cout << "pick each once" << endl;
    
    for(unsigned i = 1; i <= 6; ++i)
    {
        cin >> names;
        for(list<Character*>::iterator it = team1.begin(); it != team1.end(); it++)
        {
            if(names == (*it)->getName())
            {
                temp1.push_back(*it);
                break;
            }
        }
    }
    team1.swap(temp1);
    
    cout << endl;
    cout << "display team after" << endl;
    for(list<Character*>::iterator it = team1.begin(); it != team1.end(); ++it)
    {
        cout << (*it)->getName() << endl;
    }
    cout << endl;
    
    
    list<Character*> team2;
    team2.push_back(new Warrior("joe", MAX_HEALTH, 5, "King jim"));
    team2.push_back(new Warrior("sam", MAX_HEALTH, 6, "King jim"));
    team2.push_back(new Elf("swar", MAX_HEALTH, 4, "Ninon"));
    team2.push_back(new Elf("gwar", MAX_HEALTH, 3, "Ninon"));
    team2.push_back(new Wizard("merlin", MAX_HEALTH, 5, 8));
    team2.push_back(new Wizard("gandalf", MAX_HEALTH, 4, 6));
    
    cout << "display team before" << endl;
    for(list<Character*>::iterator it = team2.begin(); it != team2.end(); ++it)
    {
        cout << (*it)->getName() << endl;
    }
    cout << endl;    
    
    string name2;
    list<Character*> temp2;
    list<Character*>::iterator ccc = team2.begin();
    cout << "choose order of characters 1-6" << endl;
    cout << "choose character to push back" << endl;
    cout << "pick each once" << endl;
    
    for(unsigned i = 1; i <= 6; ++i)
    {
        cin >> names;
        for(list<Character*>::iterator it = team2.begin(); it != team2.end(); it++)
        {
            if(names == (*it)->getName())
            {
                temp2.push_back(*it);
                break;
            }
        }
    }   
    team2.swap(temp2);
    
    cout << endl;
    cout << "display team after" << endl;
    for(list<Character*>::iterator it = team2.begin(); it != team2.end(); ++it)
    {
        cout << (*it)->getName() << endl;
    }
    cout << endl;
    
        
    
    cout << "Attack sequence" << endl;
    while(!team1.empty() && !team2.empty())
    {
        list<Character*>::iterator it1 = team1.begin();
        list<Character*>::iterator it2 = team2.begin();
        
        while(it1 != team1.end() && it2 != team2.end())
        {
            (*it1)->attack(**it2);
            (*it2)->attack(**it1);
            
            if(!(*it1)->isAlive())
            {
                it1 = team1.erase(it1);
            }
            else
            {
                it1++;
            }
            
            if(!(*it2)->isAlive())
            {
                it2 = team2.erase(it2);
            }
            else
            {
                it2++;
            }
        }
    }
    
    if(team1.empty())
    {
        cout << "TEAM 1 WON THE GAME" << endl;
    }
    else
    {
        cout << "TEAM 2 WON THE GAME" << endl;
    }    
}