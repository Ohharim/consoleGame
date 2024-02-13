#include <iostream>
#include <cstdlib>
#include "consoleUtils.h"
#include "input.h"
#include "gameLogic.h"

using namespace std;

void drawScore(int score) {
    gotoxy(50, 0);
    cout << "score : " << score;
}
void drawDino(int dinoY) {
    gotoxy(0, dinoY);
    static bool legFlag = true;
    cout << "  " << "          ■■■■■" << "\n";
    cout << "  " << "         ■■■■■■" << "\n";
    cout << "  " << "         ■■  ■■■■ " << "\n";
    cout << "  " << "         ■■■■■■■" << "\n";
    cout << "  " << "         ■■■■■" << "\n";
    cout << "  " << "@       ■■■■■■" << "\n";
    cout << "  " << "■      ■■■■■" << "\n";
    cout << "  " << "■■   ■■■■■■■■" << "\n";
    cout << "  " << "■■■■■■■■     ■" << "\n";
    cout << "  " << " ■■■■■■■" << "\n";
    cout << "  " << "  ■■■■■■" << "\n";
    cout << "  " << "   ■■■■■" << "\n";

    if (legFlag) {
        cout << "  " << "    ■   ■" << "\n";
        cout << "  " << "    ■■  ■■" << "\n";
        legFlag = false;
    }
    else {
        cout << "  " << "  ■■   ■■" << "\n";
        legFlag = true;
    }

}

void drawCactus1(int cactusX1) {
    gotoxy(cactusX1, 22);
    cout << "  ■   ■  " << "\n";
    gotoxy(cactusX1, 23);
    cout << "  ■■■  " << "\n";
    gotoxy(cactusX1, 24);
    cout << "    ■   " << "\n";

}
void drawCactus2(int cactusX2) {
    gotoxy(cactusX2, 22);
    cout << "  ■   ■  " << "\n";
    gotoxy(cactusX2, 23);
    cout << "  ■■■  " << "\n";
    gotoxy(cactusX2, 24);
    cout << "    ■   " << "\n";

}
void drawGame();

void drawGameOver(const int score) {
    system("cls");
    int x = 45;
    int y = 10;
    gotoxy(x, y);
    cout << "==========================\n";
    gotoxy(x, y + 1);
    cout << "      G A M E O V E R     \n";
    gotoxy(x, y + 2);
    cout << "==========================\n";
    gotoxy(x + 8, y + 5);
    cout << "score : " << score;
    gotoxy(x + 5, y + 7);
    cout << "[1] RETRY";
    gotoxy(x + 5, y + 10);
    cout << "[0] QUIT";

    char choice;
    choice = GetKeyDownMenu();
    switch (choice) {
    case 49: // ASCII 값 49는 숫자키 1
        drawGame();
        break;
    case 48: // ASCII 값 51는 숫자키 3
        exit(0); // 프로그램 종료
    }

}

void drawHeart(int cnt) {
    switch (cnt) {
    case 0:
        cout << "   ♥♥♥";
        break;
    case 1:
        cout << "   ♥♥♡";
        break;
    case 2:
        cout << "   ♥♡♡";
        break;
    case 3:
        cout << "   ♡♡♡";
        break;
    }
}
void drawGameReady() {
    system("cls");
    int x = 45;
    int y = 10;
    gotoxy(x, y);
    cout << "==========================\n";
    gotoxy(x, y + 1);
    cout << "       JUMPING DINO       \n";
    gotoxy(x, y + 2);
    cout << "==========================\n";
    gotoxy(x, y + 3);
    cout << "z를 누르면 공룡이 점프해요.\n";
    gotoxy(x, y + 5);
    cout << "[1] GAME START";

    gotoxy(x, y + 7);
    cout << "[0] QUIT";

    char choice;
    choice = GetKeyDownMenu();
    switch (choice) {
    case 49: // ASCII 49 숫자키 1
        drawGame();
        break;
    case 48: // ASCII 51 숫자키 3
        exit(0); 
    }
}