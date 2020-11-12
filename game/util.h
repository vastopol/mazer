#include <ctime>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <utility>

using namespace std;

const unsigned GRID_SIZE = 10;

struct Game {
    unsigned level = 1;
    pair<int, int> goal;
    pair<int, int> position;
    char grid[GRID_SIZE][GRID_SIZE];
};

void clear();
void displayGrid(Game);
Game initGrid(Game);
bool boundsCheck(Game);
bool goalCheck(Game);
void gameOver(int);
