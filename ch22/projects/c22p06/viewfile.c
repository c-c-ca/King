#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>

#define BUFFER_SIZE 10

void print_line(void);
int main(int argc, char *argv[])
{
    FILE *fp;
    int i, n, offset;
    unsigned char buffer[BUFFER_SIZE];
    
    if (argc != 2) {
        fprintf(stderr, "usage: %s file\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    if ((fp = fopen(argv[1], "rb")) == NULL) {
        fprintf(stderr, "Can't open %s\n", argv[1]);
        exit(EXIT_FAILURE);
    }

    printf("Offset              Bytes              Characters\n");
    printf("------  -----------------------------  ----------\n");

    for (offset = 0;; offset += BUFFER_SIZE) {
        n = fread(buffer, sizeof(buffer[0]), sizeof(buffer) / sizeof(buffer[0]), fp);
        if (n == 0)
            break;

        printf("%6d ", offset);
        for (i = 0; i < n; i++)
            printf("%.2hX ", buffer[i]);
        for (; i < BUFFER_SIZE; i++)
            printf("   ", buffer[i]);
        printf("  ");
        for (i = 0; i < n; i++)
            printf("%c", isprint(buffer[i]) ? buffer[i] : '.');
        printf("\n");
    }
 
    fclose(fp);
    return 0;
}
