#ifndef STACK_H
#define STACK_H

struct Stack;
typedef struct Stack Stack;

// Creating and destroying stack
Stack * new_stack(int value);
void delete_stack(Stack ** stack);

// Length of stack
int stack_size(Stack ** stack);

// Operations on stack
void push(Stack ** stack, int value);
int peek (Stack ** stack);
int pop  (Stack ** stack);

#endif