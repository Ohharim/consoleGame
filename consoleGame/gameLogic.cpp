#include <cstdlib>
#include <ctime>
#include <windows.h>
#include "consoleUtils.h"
#include "input.h"
#include "draw.h"

//충돌 계산
bool isCollision(const int CactusX1, const int CactusX2, const int dinoY, const bool isJumping, int& cnt, bool& isHit1, bool& isHit2) {
    bool hit1 = (CactusX1 <= 8 && CactusX1 >= 0 && dinoY >= 10);
    bool hit2 = (CactusX2 <= 8 && CactusX2 >= 0 && dinoY >= 10);

    if (hit1 && !isHit1) {
        if (!isHit2) {
            cnt += 1;
            isHit1 = true;
        }
    }
    else if (!hit1) {
        isHit1 = false;
    }

    if (hit2 && !isHit2) {
        if (!isHit1) {
            cnt += 1;
            isHit2 = true;
        }
    }
    else if (!hit2) {
        isHit2 = false;
    }

    return cnt > 3;
}

void drawGame() {
    srand(time(0));
    hideCursor();

    bool isJumping = false;
    bool isWalking = true;

    bool isHit1 = false;
    bool isHit2 = false;

    const float jumpSpeed = 3.0; // 점프 속도 조절
    const float fallSpeed = 1.8; // 낙하 속도 조절

    int dinoY = 7;

    int cactusX1 = 45;
    int speed1 = 2 + rand() % 3; // 2 3 4

    int cactusX2 = 90;
    int speed2 = 2 + rand() % 3;

    int cactusY = 15;

    int cnt = 0;
    int score = 0;

    clock_t start, curr;
    start = clock(); //시작시간

    while (true)
    {
        int key = GetKeyDownGame();

        if (key == 'z' && isWalking) {
            isJumping = true;
        }
        if (isJumping) {
            dinoY -= jumpSpeed;
        }
        else {
            dinoY += fallSpeed;
        }

        if (dinoY >= 12) { //걍 걸을때
            dinoY = 12;
            isWalking = true;
            isJumping = false;
        }

        if (dinoY <= 3) { //하강 처리
            isJumping = false;
        }

        cactusX1 -= speed1; //속도 x  -방향으로 진행

        if (cactusX1 <= 0) {
            cactusX1 = 45 + rand() % 20;
            speed1 = 2 + rand() % 3;
        }
        cactusX2 -= speed2;

        if (cactusX2 <= 0) {
            cactusX2 = 90 + rand() % 20;
            speed2 = 2 + rand() % 3;
        }

        curr = clock(); //현재시간
        if (((curr - start) / CLOCKS_PER_SEC) >= 1) {
            score++;
            start = clock();
        }

        system("cls");
        drawDino(dinoY);
        drawCactus1(cactusX1);
        drawCactus2(cactusX2);

        drawScore(score);
        hideCursor();
        showCursor();

        if (isCollision(cactusX1, cactusX2, dinoY, isJumping, cnt, isHit1, isHit2)) {
            if (cnt > 3) {
                drawGameOver(score);
                break;
            }
        }

        drawHeart(cnt);
        Sleep(60);
    }
}