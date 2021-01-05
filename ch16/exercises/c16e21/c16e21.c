#include <stdio.h>

#define PRINT(x) printf("Value of " #x ": %d\n", x)

enum {NUL, SOH, STX, ETX};
enum {VT = 11, FF, CR};
enum {SO = 14, SI, DLE, CAN = 24, EM};
enum {ENQ = 45, ACK, BEL, LF = 37, ETB, ESC};

int main(void)
{
    PRINT(NUL); /* 0 */
    PRINT(SOH); /* 1 */
    PRINT(STX); /* 2 */
    PRINT(ETX); /* 3 */

    PRINT(VT);  /* 11 */
    PRINT(FF);  /* 12 */
    PRINT(CR);  /* 13 */

    PRINT(SO);  /* 14 */
    PRINT(SI);  /* 15 */
    PRINT(DLE); /* 16 */
    PRINT(CAN); /* 24 */
    PRINT(EM);  /* 25 */

    PRINT(ENQ); /* 45 */
    PRINT(ACK); /* 46 */
    PRINT(BEL); /* 47 */
    PRINT(LF);  /* 37 */
    PRINT(ETB); /* 38 */
    PRINT(ESC); /* 39 */

    return 0;
}
