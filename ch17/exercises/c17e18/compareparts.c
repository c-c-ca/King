#include <stdio.h>

#define NAME_LEN 25

struct part {
    int number;
    char name[NAME_LEN+1];
    int on_hand;
    struct part *next;
};

int compare_parts(const void *p, const void *q);

int main(void)
{
    return 0;
}

int compare_parts(const void *p, const void *q)
{
    return ((struct part *) q)->number -
           ((struct part *) p)->number;
}
