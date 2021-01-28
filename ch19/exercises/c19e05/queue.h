#ifndef QUEUE_H
#define QUEUE_H

#include <stdbool.h>   /* C99 only */

#define QUEUE_SIZE 100

typedef struct {
    int contents[QUEUE_SIZE];
    int first;
    int last;
    int num_items;
} Queue;

void insert_item(Queue *q, int i);
int remove_item(Queue *q);
int first_item(const Queue *q);
int last_item(const Queue *q);
bool is_empty(const Queue *q);

#endif
