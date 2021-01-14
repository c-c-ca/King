#include <stdio.h>
#include <stdlib.h>

struct node {
    int value;           /* data stored in the node  */
    struct node *next;   /* pointer to the next node */
};

struct node *first = NULL;

void add_to_list(struct node **list, int n);
struct node *read_numbers(void);
struct node *search_list(struct node *list, int n);
struct node *delete_from_list(struct node *list, int n);
int count_occurrences(struct node *list, int n);

int main(void)
{
    int n;
    struct node *p;

    read_numbers();

    printf("Enter number to count: ");
    scanf("%d", &n);
    printf("Number of occurrences for %d: %d\n", n, count_occurrences(first, n));

    return 0;
}

void add_to_list(struct node **list, int n)
{
    struct node *new_node;

    new_node = malloc(sizeof(struct node));
    if (new_node == NULL) {
        printf("Error: malloc failed in add_to_list\n");
        exit(EXIT_FAILURE);
    }
    new_node->value = n;
    new_node->next = *list;
    *list = new_node;
}

struct node *read_numbers(void)
{
    int n;

    printf("Enter a series of integers (0 to terminate): ");
    for (;;) {
        scanf("%d", &n);
        if (n == 0)
            return first;
        add_to_list(&first, n);
    }
}

struct node *search_list(struct node *list, int n)
{
    while (list != NULL && list->value != n)
        list = list->next;
    return list;
}

struct node *delete_from_list(struct node *list, int n)
{
    struct node *cur, *prev;

    for (cur = list, prev = NULL;
         cur != NULL && cur->value != n;
         prev = cur, cur = cur->next)
        ;
    if (cur == NULL)
        return list;              /* n was not found */
    if (prev == NULL)
        list = list->next;        /* n is in the first node */
    else
        prev->next = cur->next;   /* n is in some other node */
    free(cur);
    return list;
}

int count_occurrences(struct node *list, int n)
{
    int count = 0;

    for (; list != NULL; list = list->next)
        if (list->value == n)
            count++;

    return count;
}
