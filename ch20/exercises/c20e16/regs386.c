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
            WORD ax; WORD;
            WORD bx; WORD;
            WORD cx; WORD;
            WORD dx; WORD;
        } word;
        struct {
            BYTE al, ah; WORD;
            BYTE bl, bh; WORD;
            BYTE cl, ch; WORD;
            BYTE dl, dh; WORD;
        } byte;
    } regs;

    regs.dword.eax = 0x12345678;

    printf("AX: %hx\n", regs.word.ax);

    printf("AH: %hx\n", regs.byte.ah);
    printf("AL: %hx\n", regs.byte.al);

    return 0;
}
