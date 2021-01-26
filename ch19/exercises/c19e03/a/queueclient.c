#include <stdio.h>
#include "queue.h"

int main(void)
{
    insert_item(1);
    insert_item(2);
    printf("%d\n", first_item());
    printf("%d\n", last_item());
    while (!is_empty())
        printf("%d\n", remove_item());

    return 0;
}
