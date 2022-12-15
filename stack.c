#include "stack.h"

#include <stdlib.h>

struct Stack {
    Stack * next;
    int value;
};

Stack * new_stack(int value){
    Stack * s = malloc(sizeof(Stack));

    s->next = NULL;
    s->value = value;

    return s;
}

void delete_stack(Stack ** stack){
    Stack * next;
    while ((next = (*stack)->next) != NULL){
        free(*stack);
        *stack = next;
    }
    free(*stack);
}

int stack_size(Stack ** stack){
    int i = 1;
    Stack * next = *stack;
    while ((next = next->next) != NULL){
        i++;
    }
    return i;
}

void push(Stack ** stack, int value){
    Stack * s = malloc(sizeof(Stack));
    s->next = *stack;
    s->value = value;
    *stack = s;
}

int peek (Stack ** stack){
    return (*stack)->value;
}

int pop (Stack ** stack){
    // Record values
    int value = (*stack)->value;
    Stack * next = (*stack)->next;
    // Get rid off Stack element popped
    free(*stack);
    *stack = next;
    return value;
}