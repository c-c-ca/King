#include <stdio.h>

#define LINE(x) #x
#define LINE2(x) LINE(x)
#define LINE_FILE "Line " LINE2(__LINE__) " of file " __FILE__


int main(void)
{
    const char *str = LINE_FILE;

    printf("%s\n", str);

    return 0;
}
