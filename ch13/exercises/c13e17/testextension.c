#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>

bool test_extension(const char *file_name,
                    const char *extension);

int main(void)
{
    if (test_extension("memo.txt", "TXT"))
        printf("Extension found in file name\n");
    else
        printf("Extension not found in file name\n");

    return 0;
}

bool test_extension(const char *file_name,
                    const char *extension)
{
    const char *p = file_name, *q = extension;

    while (*p)
        if (*p++ == '.')
            break;

    while (*p && *q)
        if (toupper(*p++) != toupper(*q++))
            return false;

    return *p == *q;
}
