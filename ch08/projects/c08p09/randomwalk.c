/* Simulates a random walk */

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N              10
#define UP             0
#define DOWN           1
#define LEFT           2
#define RIGHT          3
#define NUM_DIRECTIONS 4

int main(void)
{
    bool legal_move[NUM_DIRECTIONS];
    char walk[N][N];
    int x, y, step, direction;

    srand((unsigned) time(NULL));

    for (y = 0; y < N; y++)
        for (x = 0; x < N; x++)
            walk[y][x] = '.';

    for (x = y = step = 0; (walk[y][x] = 'A' + step) < 'Z'; step++) {
        legal_move[UP] = (y > 0) && walk[y-1][x] == '.';
        legal_move[DOWN] = (y < N - 1) && walk[y+1][x] == '.';
        legal_move[LEFT] = (x > 0) && walk[y][x-1] == '.';
        legal_move[RIGHT] = (x < N - 1) && walk[y][x+1] == '.';

        if (!legal_move[UP] && !legal_move[DOWN] &&
            !legal_move[LEFT] && !legal_move[RIGHT])
            break;

        while (!legal_move[direction = rand() % NUM_DIRECTIONS])
            ;
            
        switch (direction) {
            case UP:    y--; break;
            case DOWN:  y++; break;
            case LEFT:  x--; break;
            case RIGHT: x++; break;
        }
    }

    for (y = 0; y < N; y++) {
        for (x = 0; x < N; x++)
            printf("%c ", walk[y][x]);
        printf("\n");
    }

    return 0;
}
