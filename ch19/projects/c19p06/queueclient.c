#include <stdio.h>
#include "queueADT.h"

int main(void)
{
    Queue q1, q2;
    int n;

    q1 = create(100);
    q2 = create(200);

    insert_item(q1, 1);
    insert_item(q1, 2);

    printf("First item in q1: %d\n", first_item(q1));
    printf("Last item in q1: %d\n", last_item(q1));

    n = remove_item(q1);
    printf("Removed %d from q1\n", n);
    insert_item(q2, n);
    n = remove_item(q1);
    printf("Removed %d from q1\n", n);
    insert_item(q2, n);

    destroy(q1);

    while (!is_empty(q2))
        printf("Removed %d from q2\n", remove_item(q2));

    if (is_empty(q2))
        printf("q2 is empty\n");
    else
        printf("q2 is not empty\n");

    destroy(q2);

    return 0;
}
