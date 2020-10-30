/* Simulates a random walk */

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N              10
#define UP              0
#define DOWN            1
#define LEFT            2
#define RIGHT           3
#define NUM_DIRECTIONS  4

int main(void)
{
    char matrix[N][N], step;
    int x, y, direction;
    bool valid_direction[NUM_DIRECTIONS];

    srand((unsigned) time(NULL));

    for (y = 0; y < N; y++)
        for (x = 0; x < N; x++)
            matrix[y][x] = '.';

    x = y = 0;
    for (step = 'A'; (matrix[y][x] = step) < 'Z'; step++) {
        if (!(valid_direction[UP] = y > 0 && matrix[y-1][x] == '.'))
            break;
        if (!(valid_direction[DOWN] = y < N - 1 && matrix[y+1][x] == '.'))
            break;
        if (!(valid_direction[LEFT] = x > 0 && matrix[y][x-1] == '.'))
            break;
        if (!(valid_direction[RIGHT] = x < N - 1 && matrix[y][x+1] == '.'))
            break;

        while (!valid_direction[direction = rand() % NUM_DIRECTIONS])
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
            printf("%c ", matrix[y][x]);
        printf("\n");
    }

    return 0;
}
