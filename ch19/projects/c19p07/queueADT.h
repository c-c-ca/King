#ifndef QUEUE_H
#define QUEUE_H

#include <stdbool.h>   /* C99 only */

typedef int Item;

typedef struct queue_type *Queue;

Queue create(void);
void destroy(Queue q);
void insert_item(Queue q, Item i);
Item remove_item(Queue q);
Item first_item(Queue q);
Item last_item(Queue q);
bool is_empty(Queue q);

#endif
