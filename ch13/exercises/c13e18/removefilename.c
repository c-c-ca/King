#include <stdio.h>

void remove_filename(char *url);

int main(void)
{
    char url[] = "http://www.knking.com/index.html";

    remove_filename(url);

    printf("%s\n", url);

    return 0;
}

void remove_filename(char *url)
{
    while (*url)
        url++;

    while (*--url != '/')
        ;
    *url = '\0';
}
