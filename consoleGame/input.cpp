#include <conio.h> // _kbhit(), _getch() �Լ��� ����ϱ� ���� �ʿ�
#include "input.h"

int GetKeyDownGame() {
    if (_kbhit() != 0) { //Ű���� �Է� Ȯ��
        return _getch(); //�Էµ� Ű���� �� ��ȯ
    }
    return 0; 
}

int GetKeyDownMenu() {
    while (true) {
        if (_kbhit() != 0) { 
            return _getch(); 
        }
    }
}