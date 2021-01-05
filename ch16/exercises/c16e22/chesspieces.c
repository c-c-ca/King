#include <stdio.h>

#define PRINT(x) printf("Value of " #x ": %d\n", x)

enum chess_pieces {KING, QUEEN, ROOK, BISHOP, KNIGHT, PAWN};

#ifdef A
const int piece_value[] = {200, 9, 5, 3, 3, 1};
#endif

#ifdef B
const int piece_value[] = {
    [KING] = 200,
    [QUEEN] = 9,
    [ROOK] = 5,
    [BISHOP] = 3,
    [KNIGHT] = 3,
    [PAWN] = 1
};
#endif

int main(void)
{
    PRINT(piece_value[BISHOP]);

    return 0;
}
