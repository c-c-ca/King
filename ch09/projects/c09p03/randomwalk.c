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

void generate_random_walk(char walk[N][N]);
void print_array(char walk[N][N]);

int main(void)
{
    char walk[N][N];

    srand((unsigned) time(NULL));
    generate_random_walk(walk);
    print_array(walk);

    return 0;
}

void generate_random_walk(char walk[N][N])
{
    int x, y, step, direction;
    bool legal_move[NUM_DIRECTIONS];

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
}

void print_array(char walk[N][N])
{
    int x, y;

    for (y = 0; y < N; y++) {
        for (x = 0; x < N; x++)
            printf("%c ", walk[y][x]);
        printf("\n");
    }
}
