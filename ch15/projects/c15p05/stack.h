#ifndef STACK_H
#define STACK_H

#include <stdbool.h>

/*****************************************************
 * make_empty: Remove all elements from the stack.   *
 *****************************************************/
void make_empty(void);

/*****************************************************
 * is_empty: The stack is empty.                     *
 *****************************************************/
bool is_empty(void);

/*****************************************************
 * is_full: The stack is full.                       *
 *****************************************************/
bool is_full(void);

/*****************************************************
 * push: Push i on top of the stack.                 *
 *****************************************************/
void push(int i);

/*****************************************************
 * pop: Remove an element from the top of the stack. *
 *****************************************************/
int pop(void);

#endif
