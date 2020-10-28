#define N 8

int main(void)
{
    char checker_board[N][N];
    int i, j;

    for (i = 0; i < N; i++)
        for (j = 0; j < N; j++)
            checker_board[i][j] = ((i + j) % 2 == 0) ? 'B' : 'R';
    
    return 0;
}
