//#include <iostream>
//#include <conio.h> //값 입력받음
//#include <Windows.h>
//#include <time.h>
//#include <ctime>  // for std::time
//#include <cstdlib>  // for std::rand and std::srand
#include "consoleUtils.h"
#include "input.h"
#include "draw.h"
#include "gameLogic.h"
using namespace std;

//void SetConsoleView() {
//    system("mode con:cols=100 lines=25");
//}
//int GetKeyDownGame() {
//    if (_kbhit() != 0) { //키보드 입력 확인
//        return _getch(); //입력된 키보드 값 반환
//    }
//    return 0; //키 입력이 없으면 0 반환
//}
//
//int GetKeyDownMenu() {
//    while (true) { // 무한루프
//        if (_kbhit() != 0) { //키보드 입력 확인
//            return _getch(); //입력된 키보드 값 반환
//        }
//    }
//}

//void gotoxy(int x, int y) {
//    COORD pos;
//    pos.X = x;
//    pos.Y = y;
//    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
//}
//void hideCursor() {
//    CONSOLE_CURSOR_INFO cursorInfo;
//    cursorInfo.dwSize = 1;
//    cursorInfo.bVisible = FALSE;
//    SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursorInfo);
//}
//
//void showCursor() {
//    CONSOLE_CURSOR_INFO cursorInfo;
//    cursorInfo.dwSize = 1;
//    cursorInfo.bVisible = TRUE;
//    SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursorInfo);
//}

//void drawScore(int score) {
//    gotoxy(50, 0);
//    cout << "score : " << score;
//}
//void drawDino(int dinoY) {
//    gotoxy(0, dinoY);
//    static bool legFlag = true;
//    cout << "  " << "          ■■■■■" << "\n";
//    cout << "  " << "         ■■■■■■" << "\n";
//    cout << "  " << "         ■■  ■■■■ " << "\n";
//    cout << "  " << "         ■■■■■■■" << "\n";
//    cout << "  " << "         ■■■■■" << "\n";
//    cout << "  " << "@       ■■■■■■" << "\n";
//    cout << "  " << "■      ■■■■■" << "\n";
//    cout << "  " << "■■   ■■■■■■■■" << "\n";
//    cout << "  " << "■■■■■■■■     ■" << "\n";
//    cout << "  " << " ■■■■■■■" << "\n";
//    cout << "  " << "  ■■■■■■" << "\n";
//    cout << "  " << "   ■■■■■" << "\n";
//
//    if (legFlag) {
//        cout << "  " << "    ■   ■" << "\n";
//        cout << "  " << "    ■■  ■■" << "\n";
//        legFlag = false;
//    }
//    else {
//        cout << "  " << "  ■■   ■■" << "\n";
//        legFlag = true;
//    }
//
//}
//
//void drawCactus1(int cactusX1) {
//    gotoxy(cactusX1, 22);
//    cout << "  ■   ■  " << "\n";
//    gotoxy(cactusX1, 23);
//    cout << "  ■■■  " << "\n";
//    gotoxy(cactusX1, 24);
//    cout << "    ■   " << "\n";
//
//}
//void drawCactus2(int cactusX2) {
//    gotoxy(cactusX2, 22);
//    cout << "  ■   ■  " << "\n";
//    gotoxy(cactusX2, 23);
//    cout << "  ■■■  " << "\n";
//    gotoxy(cactusX2, 24);
//    cout << "    ■   " << "\n";
//
//}
//void drawGame();
//
//void drawGameOver(const int score) {
//    system("cls");
//    int x = 45;
//    int y = 10;
//    gotoxy(x, y);
//    cout << "==========================\n";
//    gotoxy(x, y + 1);
//    cout << "=====G A M E O V E R======\n";
//    gotoxy(x, y + 2);
//    cout << "==========================\n";
//    gotoxy(x + 8, y + 5);
//    cout << "score : " << score;
//    gotoxy(x + 5, y + 7);
//    cout << "[1] RETRY";
//
//    gotoxy(x + 5, y + 10);
//    cout << "[0] QUIT";
//
//    char choice;
//    choice = GetKeyDownMenu();
//    switch (choice) {
//    case 49: // ASCII 값 49는 숫자키 1
//        drawGame();
//        break;
//    case 48: // ASCII 값 51는 숫자키 3
//        exit(0); // 프로그램 종료
//    }
//
//}
//
//void drawHeart(int cnt) {
//    switch (cnt) {
//    case 0:
//        cout << "   ♥♥♥";
//        break;
//    case 1:
//        cout << "   ♥♥♡";
//        break;
//    case 2:
//        cout << "   ♥♡♡";
//        break;
//    case 3:
//        cout << "   ♡♡♡";
//        break;
//    }
//}

//bool isCollision(const int CactusX1, const int CactusX2, const int dinoY, const bool isJumping, int& cnt, bool& isHit1, bool& isHit2) {
//    bool hit1 = (CactusX1 <= 8 && CactusX1 >= 0 && dinoY >= 10);
//    bool hit2 = (CactusX2 <= 8 && CactusX2 >= 0 && dinoY >= 10);
//
//    if (hit1 && !isHit1) {
//        if (!isHit2) {
//            cnt += 1;
//            isHit1 = true;
//        }
//    }
//    else if (!hit1) {
//        isHit1 = false;
//    }
//
//    if (hit2 && !isHit2) {
//        if (!isHit1) {
//            cnt += 1;
//            isHit2 = true;
//        }
//    }
//    else if (!hit2) {
//        isHit2 = false;
//    }
//
//    return cnt > 3;
//}
//
//void drawGame() {
//    srand(time(0));
//    hideCursor();
//
//    bool isJumping = false;
//    bool isWalking = true;
//
//    bool isHit1 = false;
//    bool isHit2 = false;
//
//    const float jumpSpeed = 3.0; // 점프 속도 조절
//    const float fallSpeed = 1.8; // 낙하 속도 조절
//
//    int dinoY = 7;
//
//    int cactusX1 = 45;
//    int speed1 = 2 + rand() % 3; // 2 3 4
//
//    int cactusX2 = 90;
//    int speed2 = 2 + rand() % 3;
//
//    int cactusY = 15;
//    int cnt = 0;
//    int score = 0;
//    clock_t start, curr;
//    start = clock(); //시작시간
//
//    while (true)
//    {
//        int key = GetKeyDownGame();
//
//        if (key == 'z' && isWalking) {
//            isJumping = true;
//        }
//        if (isJumping) {
//            dinoY -= jumpSpeed;
//        }
//        else {
//            dinoY += fallSpeed;
//        }
//
//        if (dinoY >= 12) {
//            dinoY = 12;
//            isWalking = true;
//            isJumping = false;
//        }
//
//        if (dinoY <= 3) {
//            isJumping = false;
//        }
//
//        cactusX1 -= speed1; //속도 x  -방향으로 진행
//
//        if (cactusX1 <= 0) {
//            cactusX1 = 45 + rand() % 20;
//            speed1 = 2 + rand() % 3;
//        }
//        cactusX2 -= speed2;
//
//        if (cactusX2 <= 0) {
//            cactusX2 = 90 + rand() % 20;
//            speed2 = 2 + rand() % 3;
//        }
//        curr = clock(); //현재시간
//        if (((curr - start) / CLOCKS_PER_SEC) >= 1) {
//            score++;
//            start = clock();
//        }
//
//        system("cls");
//        drawDino(dinoY);
//        drawCactus1(cactusX1);
//        drawCactus2(cactusX2);
//
//        drawScore(score);
//        hideCursor();
//        showCursor();
//
//        if (isCollision(cactusX1, cactusX2, dinoY, isJumping, cnt, isHit1, isHit2)) {
//            if (cnt >= 3) {
//                drawGameOver(score);
//                break;
//            }
//        }
//
//        drawHeart(cnt);
//        Sleep(60);
//    }
//}
//void drawGameReady() {
//    system("cls");
//    int x = 45;
//    int y = 10;
//    gotoxy(x, y);
//    cout << "==========================\n";
//    gotoxy(x, y + 1);
//    cout << "=========DINO RUN=========\n";
//    gotoxy(x, y + 2);
//    cout << "==========================\n";
//    gotoxy(x, y + 3);
//    cout << "z를 누르면 공룡이 점프해요.\n";
//    gotoxy(x, y + 5);
//    cout << "[1] GAME START";
//
//    gotoxy(x, y + 7);
//    cout << "[0] QUIT";
//
//    char choice;
//    choice = GetKeyDownMenu();
//    switch (choice) {
//    case 49: // ASCII 값 49는 숫자키 1
//        drawGame();
//        break;
//    case 48: // ASCII 값 51는 숫자키 3
//        exit(0); // 프로그램 종료
//    }
//}



int main() {
    SetConsoleView();
    drawGameReady();
    return 0;
}
