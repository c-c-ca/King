#ifndef QUEUE_H
#define QUEUE_H

#include <stdbool.h>   /* C99 only */

void insert_item(int i);
int remove_item(void);
int first_item(void);
int last_item(void);
bool is_empty(void);

#endif
