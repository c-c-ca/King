#include <stdio.h>
#include <stdlib.h>
#include "queueADT.h"

#define QUEUE_SIZE 100

struct queue_type {
    Item contents[QUEUE_SIZE];
    int first;
    int last;
    int size;
};

static void terminate(char *message)
{
    printf("%d\n", message);
    exit(EXIT_FAILURE);
}

Queue create(void)
{
    Queue q = malloc(sizeof(struct queue_type));
    if (q == NULL)
        terminate("Error in create: queue could not be created.");
    q->first = 0;
    q->last = -1;
    q->size = 0;
    return q;
}

void destroy(Queue q)
{
    free(q);
}

bool is_empty(Queue q)
{
    return q->size == 0;
}

void insert_item(Queue q, Item i)
{
    if (q->size == QUEUE_SIZE)
        printf("Error in insert: queue is full.");

    if (q->last == QUEUE_SIZE - 1)
        q->last = -1;
    q->contents[++q->last] = i; 
    q->size++;
}

Item remove_item(Queue q)
{
    Item i;

    if (is_empty(q))
        printf("Error in remove: queue is empty.");

    i = q->contents[q->first++];
    if (q->first == QUEUE_SIZE)
        q->first = 0;
    q->size--;
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
