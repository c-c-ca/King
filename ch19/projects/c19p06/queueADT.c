#include <stdio.h>
#include <stdlib.h>
#include "queueADT.h"

struct queue_type {
    Item *contents;
    int first;
    int last;
    int num_items;
    int size;
};

static void terminate(char *message)
{
    printf("%d\n", message);
    exit(EXIT_FAILURE);
}

Queue create(int size)
{
    Queue q = malloc(sizeof(struct queue_type));
    if (q == NULL)
        terminate("Error in create: queue could not be created.");
    q->contents = malloc(size * sizeof(Item));
    if (q->contents == NULL) {
        free(q);
        terminate("Error in create: queue could not be created.");
    }
    q->first = 0;
    q->last = -1;
    q->num_items = 0;
    q->size = size;
    return q;
}

void destroy(Queue q)
{
    free(q);
}

bool is_empty(Queue q)
{
    return q->num_items == 0;
}

void insert_item(Queue q, Item i)
{
    if (q->num_items == q->size)
        printf("Error in insert: queue is full.");

    if (q->last == q->size - 1)
        q->last = -1;
    q->contents[++q->last] = i; 
    q->num_items++;
}

Item remove_item(Queue q)
{
    Item i;

    if (is_empty(q))
        printf("Error in remove: queue is empty.");

    i = q->contents[q->first++];
    if (q->first == q->size)
        q->first = 0;
    q->num_items--;
    return i;
}

Item first_item(Queue q)
{
    if (is_empty(q))
        printf("Error in first: queue is empty.");
    return q->contents[q->first];
}

Item last_item(Queue q)
{
    if (is_empty(q))
        printf("Error in last: queue is empty.");
    return q->contents[q->last];
}
