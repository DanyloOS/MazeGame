#include <iostream>
#include <conio.h>
#include <fstream>

using namespace std;

static const int SIZEOFMAP = 10;
static bool IsGameOver = 0;

static char Map[SIZEOFMAP][SIZEOFMAP];
struct PlayerXY
{
    int x;
    int y;
} static player;

inline void setUp();
inline void getMapFromTxt();
inline void getUserMove();
inline void logic(char pmove);
inline void printMap();

int main()
{
    cout << "press any key to start the game\n";
    getch();

    setUp();
    while(!IsGameOver){
      getUserMove();
      printMap();
    }
    cout << "\nCongrats! You won!\n";
}

inline void setUp()
{
    getMapFromTxt();
    //seting start possition;
    player.x = 1;
    player.y = 1;
    printMap();
}
inline void getMapFromTxt()
{
    ifstream fileMap;
    fileMap.open("D:\\map.txt");

    if(!fileMap.is_open()) {
        cout << "there is some problem:(";
        return;
    }

    for (int x = 0; !fileMap.eof(); x++) {
        fileMap.getline(Map[x],SIZEOFMAP + 1,'\n');
    }

    fileMap.close();
}
inline void printMap()
{
    system("cls");
    Map[player.x][player.y] = '8';

    for(int x = 0; x < SIZEOFMAP; x++){
        for(auto symbol : Map[x])
            switch (symbol) {
            case '0': {
               cout << " ";
               break;
           }
            case '1': {
                cout << '#';
                break;
           }
            case '6': {
               cout << 'H';
               break;
           }
            case '9': {
               cout << 'H';
               break;
           }
            case '8': {
                cout << 'O';
                break;
            }
            }
        cout << endl;
    }
}
inline void getUserMove()
{
    char pmove = getch();
    logic(pmove);
}
inline void logic(char pmove)
{
    switch (pmove) {
    case 'w': {
        if (Map[player.x - 1][player.y] != '1') {
            Map[player.x--][player.y] = '0';
        }
        break;
    }
    case 'a': {
        if (Map[player.x][player.y - 1] != '1') {
            Map[player.x][player.y--] = '0';
        }
        break;
    }
    case 's': {
        if (Map[player.x + 1][player.y] != '1') {
            Map[player.x++][player.y] = '0';
        }
        break;
    }
    case 'd': {
        if (Map[player.x][player.y + 1] != '1') {
            Map[player.x][player.y++] = '0';
        }
        break;
    }
    }

    if (Map[player.x][player.y] == '9')
        IsGameOver = 1;
}
