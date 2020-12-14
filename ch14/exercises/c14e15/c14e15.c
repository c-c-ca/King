#include <stdio.h>

#define FRENCH
#if defined(ENGLISH)
#define MSG "Insert Disk 1"
#elif defined(FRENCH)
#define MSG "Inserez Le Disque 1"
#elif defined(SPANISH)
#define MSG "Inserte El Disco 1"
#endif

int main(void)
{
    printf("%s\n", MSG);

    return 0;
}
