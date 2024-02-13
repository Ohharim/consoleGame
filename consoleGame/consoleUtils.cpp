#include "draw.h"
#include "gameLogic.h"
#include "input.h"
#include <iostream>
#include <cstdlib>
#include <windows.h>


void SetConsoleView() {
    system("mode con:cols=100 lines=25");
}
void gotoxy(int x, int y) { //��ǥ �̵�
    COORD pos;
    pos.X = x;
    pos.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}
void hideCursor() {
    CONSOLE_CURSOR_INFO cursorInfo; //�ܼ� â�� Ŀ�� ���� ����ü�� �ν��Ͻ�
    cursorInfo.dwSize = 1; //Ŀ�� ũ�� ����
    cursorInfo.bVisible = FALSE; //���ü� ����
    SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursorInfo); 
    //�ܼ�â Ŀ�� ������ cursorInfo�� ����
}

void showCursor() {
    CONSOLE_CURSOR_INFO cursorInfo;
    cursorInfo.dwSize = 1;
    cursorInfo.bVisible = TRUE;
    SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursorInfo);
}
