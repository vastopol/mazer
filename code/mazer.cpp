#include "Character.h"
#include "Game.h"

int main() {
  srand(time(NULL));
  Game board = initGrid(Game());
  char input[1];

  cout << "Player choice:\n1: Elf\n2: Warrior\n3: Wizard" << endl;
  scanf("%c", input);
  getchar();
  cout << endl;
  board.player = playerChoice(*input);

  do {
    displayGrid(board);
    pair<int, int> prevPosition = board.position;
    scanf("%c", input);
    getchar();
    
    // Move
    switch (*input) {
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
      cout << "Input Error: '" << input << "'" << endl;
      break;
    }

    // Combat
    if (board.grid[board.position.first][board.position.second] == '!') {
      cout << "Combat" << endl;
      int spread = rand() % 2 + 1;  // 1 to 3
      char choice = spread + 48;  // convert to ascii (FIX)
      Character* enemy = playerChoice(choice);
      while (enemy->isAlive() && board.player->isAlive()) {
        if(rand() % 1) {
          board.player->attack(*enemy);
          enemy->attack(*board.player);
        }
        else {
          enemy->attack(*board.player);
          board.player->attack(*enemy);
        }
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
    else if (!board.player->isAlive()) {
      gameOver(2);
    }
    
    // Update Position
    board.grid[prevPosition.first][prevPosition.second] = ' ';
    board.grid[board.position.first][board.position.second] = '@';

  } while (true);
}
