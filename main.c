#include "stack.h"

#include <stdio.h>

int main(void) {
    Stack * stack = new_stack(0);

    for (int i = 1; i < 1000; i++){
        push(&stack, i);
    }

    printf("Size: %d\n", stack_size(&stack));
    printf("Top of stack: %d\n", peek(&stack));

    while (stack_size(&stack) > 0){
        printf("%d\n", pop(&stack));
    }

    delete_stack(&stack);

    return 0;
}