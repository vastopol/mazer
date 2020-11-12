#include "util.h"

int main() {
  srand(time(NULL));
  Game board = initGrid(Game());

  do {
    clear();
    displayGrid(board);

    pair<int, int> prevPosition = board.position;

    // Move
    switch (getchar()) {
    case 'w': // U
      board.position.first--;
      break;
    case 's': // D
      board.position.first++;
      break;
    case 'a': // L
      board.position.second--;
      break;
    case 'd': // R
      board.position.second++;
      break;
    default:
      cout << "Input Error" << endl;
      break;
    }

    // Combat
    if (board.grid[board.position.first][board.position.second] == '!') {
      clear();
      cout << "Combat" << endl;
      while (true) {
      }
    }

    // Check Conditions
    if (goalCheck(board)) {
      board.level++;
      board = initGrid(board);
      continue;
    }
    else if (boundsCheck(board)) {
      gameOver(1);
    } 
    else if (false) {
      // health check for player
      gameOver(2);
    }
    
    // Update Position
    board.grid[prevPosition.first][prevPosition.second] = ' ';
    board.grid[board.position.first][board.position.second] = '@';

  } while (true);
}
