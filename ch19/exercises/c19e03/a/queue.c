#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

#define QUEUE_SIZE 100

static int contents[QUEUE_SIZE];
static int first = 0;
static int last = -1;
static int size = 0;

static void terminate(char *message)
{
    printf("%d\n", message);
    exit(EXIT_FAILURE);
}

bool is_empty(void)
{
    return size == 0;
}

void insert_item(int i)
{
    if (size == QUEUE_SIZE)
        printf("Error in insert: queue is full.");

    if (last == QUEUE_SIZE - 1)
        last = -1;
    contents[++last] = i; 
    size++;
}

int remove_item(void)
{
    int i;

    if (is_empty())
        printf("Error in remove: queue is empty.");

    i = contents[first++];
    if (first == QUEUE_SIZE)
        first = 0;
    size--;
    return i;
}

int first_item(void)
{
    if (is_empty())
        printf("Error in first: queue is empty.");
    return contents[first];
}

int last_item(void)
{
    if (is_empty())
        printf("Error in last: queue is empty.");
    return contents[last];
}
