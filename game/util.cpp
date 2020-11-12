#include "util.h"

void clear() {
  cout << "\033c";
  return;
}

void displayGrid(Game game) {
  // pairs (y,x) for display, since format is quad IV on graph
  cout << "Level: " << game.level << endl;
  cout << "Index: " << '(' << game.position.second << ',' << game.position.first
       << ')' << endl
       << endl;
  cout << '#';
  for (int i = 0; i < (2 * GRID_SIZE) + 1; i++) {
    cout << '_';
  }
  cout << endl;
  for (int i = 0; i < GRID_SIZE; i++) {
    cout << ' ' << '|';
    for (int j = 0; j < GRID_SIZE; j++) {
      cout << game.grid[i][j] << '|';
    }
    cout << endl;
  }
  cout << endl;
}

Game initGrid(Game game) {
  int x = -1;
  int y = -1;

  // Blank grid
  for (int i = 0; i < GRID_SIZE; i++) {
    for (int j = 0; j < GRID_SIZE; j++) {
      game.grid[i][j] = ' ';
    }
  }

  // Start point
  x = rand() % 4;
  y = rand() % 4;
  game.grid[x][y] = '@';
  game.position.first = x;
  game.position.second = y;

  // End point
  x = rand() % 4 + 4;
  y = rand() % 4 + 4;
  game.grid[x][y] = '$';
  game.goal.first = x;
  game.goal.second = y;

  // Enemies
  x = rand() % 4 + 2;
  y = rand() % 4 + 2;
  if (game.grid[x][y] == ' ') {
    game.grid[x][y] = '!';
  }

  x = rand() % 4 - 2;
  y = rand() % 4 - 2;
  if (game.grid[x][y] == ' ') {
    game.grid[x][y] = '!';
  }

  return game;
}

bool boundsCheck(Game game) {
  return (game.position.first < 0)                         ? true
         : false || (game.position.first > GRID_SIZE - 1)  ? true
         : false || (game.position.second < 0)             ? true
         : false || (game.position.second > GRID_SIZE - 1) ? true
                                                           : false;
}

bool goalCheck(Game game) {
  return (game.position.first == game.goal.first) &&
         (game.position.second == game.goal.second);
}

void gameOver(int i) {
  switch (i) {
  case 1:
    cout << '\n' << "You touched the wall and died." << endl;
    break;
  case 2:
    cout << '\n' << "You were killed in battle." << endl;
    break;
  default:
    break;
  }
  cout << "GAME OVER" << endl;
  exit(0);
}