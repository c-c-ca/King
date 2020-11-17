#include <stdio.h>

int evaluate_position(char board[8][8]);

int main(void)
{
    char chess_board[8][8] = {{'r', 'n', 'b', 'q', 'k', 'b', 'n', 'r'},
                              {'p', 'p', 'p', 'p', 'p', 'p', 'p', 'p'},
                              {' ', '.', ' ', '.', ' ', '.', ' ', '.'},
                              {'.', ' ', '.', ' ', '.', ' ', '.', ' '},
                              {' ', '.', ' ', '.', ' ', '.', ' ', '.'},
                              {'.', ' ', '.', ' ', '.', ' ', '.', ' '},
                              {'P', 'P', 'P', 'P', 'P', 'P', 'P', 'P'},
                              {'R', 'N', 'B', 'Q', 'K', 'B', 'N', 'R'}};

    printf("Sum of pieces: %d\n", evaluate_position(chess_board));
    return 0;
}

int evaluate_position(char board[8][8])
{
    int sum = 0;
    char *p = board[0];

    while (p < board[8])
        switch (*p++) {
            case 'Q': sum += 9; break;
            case 'R': sum += 5; break;
            case 'B': sum += 3; break;
            case 'N': sum += 3; break;
            case 'P': sum += 1; break;
            case 'q': sum -= 9; break;
            case 'r': sum -= 5; break;
            case 'b': sum -= 3; break;
            case 'n': sum -= 3; break;
            case 'p': sum -= 1; break;
        }

    return sum;
}
