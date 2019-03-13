#include <iostream>
#include <conio.h>
using namespace std;

static char Map[10][10];
struct PlayerXY
{
    int x;
    int y;
} static player;

//void getMapFromTxt();
void fillMap();
void printMap();
void getUserMove();
void movePlayer();
void logic();
bool isGameOver();
void setUp();


int main()
{
    cout << "press any key to start the game\n";
    getch();

    setUp();
    while(isGameOver() != 1){
      getUserMove();
      movePlayer();
      logic();
      printMap();
    }
}
