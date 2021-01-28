#include <stdio.h>
#include <stdlib.h>
#include "queueADT.h"

struct node {
    Item data;
    struct node *next;
};

struct queue_type {
    struct node *first;
    struct node *last;
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
    q->first = NULL;
    q->last = NULL;
    return q;
}

void destroy(Queue q)
{
    while (!is_empty(q))
        remove_item(q);
    free(q);
}

bool is_empty(Queue q)
{
    return q->first == NULL;
}

void insert_item(Queue q, Item i)
{
    struct node *new_node = malloc(sizeof(struct node));
    if (new_node == NULL)
        terminate("Error in insert: queue is full.");

    new_node->data = i;
    new_node->next = NULL;

    if (is_empty(q))
        q->first = q->last = new_node;
    else {
        q->last->next = new_node;
        q->last = new_node;
    }
}

Item remove_item(Queue q)
{
    struct node *old_first;
    Item i;

    if (is_empty(q))
        terminate("Error in remove: queue is empty.");

    old_first = q->first;
    i = q->first->data;
    q->first = q->first->next;
    free(old_first);
    return i;
}

Item first_item(Queue q)
{
    if (is_empty(q))
        terminate("Error in first: queue is empty.");
    return q->first->data;
}

Item last_item(Queue q)
{
    if (is_empty(q))
        terminate("Error in last: queue is empty.");
    return q->last->data;
}
