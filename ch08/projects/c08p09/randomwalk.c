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
    char step, matrix[N][N] = {0};
    int x, y, direction;
    bool valid_direction[NUM_DIRECTIONS];

    srand((unsigned) time(NULL));

    x = y = 0;
    for (step = 'A'; (matrix[y][x] = step) < 'Z'; step++) {
        valid_direction[UP] = (y > 0) && !matrix[y-1][x];
        valid_direction[DOWN] = (y < N - 1) && !matrix[y+1][x];
        valid_direction[LEFT] = (x > 0) && !matrix[y][x-1];
        valid_direction[RIGHT] = (x < N - 1) && !matrix[y][x+1];

        if (!valid_direction[UP] && !valid_direction[DOWN] &&
            !valid_direction[LEFT] && !valid_direction[RIGHT])
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
            if (matrix[y][x])
                printf("%c ", matrix[y][x]);
            else
                printf(". ");
        printf("\n");
    }

    return 0;
}
