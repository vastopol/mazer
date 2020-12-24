#include <ctime>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <string>
#include <utility>
#include <vector>

#include "Character.h"
#include "Elf.h"
#include "Warrior.h"
#include "Wizard.h"

using namespace std;

const unsigned GRID_SIZE = 10;
const string player1Name = "Player1";
const string player1Team = "Team1";

struct Game {
    unsigned level = 1;
    pair<int, int> goal;
    pair<int, int> position;
    Character* player;
    vector<pair<int,int>> enemyPositions;
    char grid[GRID_SIZE][GRID_SIZE];
};

void clear();
void displayGrid(Game);
Game initGrid(Game);
Character* playerChoice(char);
bool boundsCheck(Game);
bool goalCheck(Game);
void gameOver(int);
