#include <stdio.h>

#define N 8

int main(void)
{
    char chess_board[][N] = {{'r', 'n', 'b', 'q', 'k', 'b', 'n', 'r'},
                             {'p', 'p', 'p', 'p', 'p', 'p', 'p', 'p'},
                             {' ', '.', ' ', '.', ' ', '.', ' ', '.'},
                             {'.', ' ', '.', ' ', '.', ' ', '.', ' '},
                             {' ', '.', ' ', '.', ' ', '.', ' ', '.'},
                             {'.', ' ', '.', ' ', '.', ' ', '.', ' '},
                             {'P', 'P', 'P', 'P', 'P', 'P', 'P', 'P'},
                             {'R', 'N', 'B', 'Q', 'K', 'B', 'N', 'R'}};

    return 0;
}