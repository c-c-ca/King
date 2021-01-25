#ifndef QUEUE_H
#define QUEUE_H

#include <stdbool.h>   /* C99 only */

void insert(int i);
int remove(void);
int first(void);
int last(void);
bool is_empty(void);

#endif
