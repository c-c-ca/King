#include <stdio.h>

typedef unsigned char BYTE;
typedef unsigned short WORD;
typedef unsigned long DWORD;

int main(void)
{
    union {
        struct {
            DWORD eax, ebx, ecx, edx;
        } dword;
        struct {
            WORD ax, _a, bx, _b, cx, _c, dx, _d;
        } word;
        struct {
            BYTE al, ah; WORD _a;
            BYTE bl, bh; WORD _b;
            BYTE cl, ch; WORD _c;
            BYTE dl, dh; WORD _d;
        } byte;
    } regs;

    regs.dword.eax = 0x12345678;

    printf("AX: %hx\n", regs.word.ax);

    printf("AH: %hx\n", regs.byte.ah);
    printf("AL: %hx\n", regs.byte.al);

    return 0;
}
