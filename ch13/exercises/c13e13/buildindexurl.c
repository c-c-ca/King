#include <stdio.h>
#include <string.h>

#define N 20

void build_index_url(const char *domain, char *index_url);

int main(void)
{
    char domain[N], index_url[N];

    scanf("%s", domain);
    build_index_url(domain, index_url);
    printf("%s\n", index_url);

    return 0;
}

void build_index_url(const char *domain, char *index_url)
{
    strcpy(index_url, "http://www.");
    strcat(index_url, domain);
    strcat(index_url, "/index.html");
}
