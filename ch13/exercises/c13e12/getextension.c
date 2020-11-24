#include <stdio.h>
#include <string.h>

#define N 10

void get_extension(const char *file_name, char *extension);

int main(void)
{
    char file_name[N], extension[N];

    printf("Enter file name: ");
    scanf("%s", file_name);

    get_extension(file_name, extension);

    printf("Extension: %s\n", extension);

    return 0;
}

void get_extension(const char *file_name, char *extension)
{
    const char *p = file_name;

    while (*p != '\0')
        if (*p++ == '.')
            break;

    strcpy(extension, p);
}
