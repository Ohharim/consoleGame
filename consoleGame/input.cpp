#include <conio.h> // _kbhit(), _getch() 함수를 사용하기 위해 필요
#include "input.h"

int GetKeyDownGame() {
    if (_kbhit() != 0) { //키보드 입력 확인
        return _getch(); //입력된 키보드 값 반환
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