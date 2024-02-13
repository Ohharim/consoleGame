#include "draw.h"
#include "gameLogic.h"
#include "input.h"
#include <iostream>
#include <cstdlib>
#include <windows.h>


void SetConsoleView() {
    system("mode con:cols=100 lines=25");
}
void gotoxy(int x, int y) { //좌표 이동
    COORD pos;
    pos.X = x;
    pos.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}
void hideCursor() {
    CONSOLE_CURSOR_INFO cursorInfo; //콘솔 창의 커서 정보 구조체와 인스턴스
    cursorInfo.dwSize = 1; //커서 크기 설정
    cursorInfo.bVisible = FALSE; //가시성 설정
    SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursorInfo); 
    //콘솔창 커서 정보를 cursorInfo로 설정
}

void showCursor() {
    CONSOLE_CURSOR_INFO cursorInfo;
    cursorInfo.dwSize = 1;
    cursorInfo.bVisible = TRUE;
    SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursorInfo);
}
