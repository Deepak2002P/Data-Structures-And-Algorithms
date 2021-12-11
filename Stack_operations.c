#include <stdio.h>
#include <stdlib.h>
struct stack
{
    int size;
    int top;
    int *arr;
};

int isEmpty(struct stack *ptr)
{
    if (ptr->top == -1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int isFull(struct stack *ptr)
{
    if (ptr->top == ptr->size - 1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void push(struct stack *ptr, int val)
{
    if (isFull(ptr))
    {
        printf("Stack Overflow! cannot push %d to the stack\n", val);
    }
    else
    {
        ptr->top++;
        ptr->arr[ptr->top] = val;
    }
}

int pop(struct stack *ptr)
{
    int val = ptr->arr[ptr->top];
    if (isEmpty(ptr))
    {
        printf("Stack Underflow! cannot pop from the stack");
        return -1;
    }
    else
    {
        ptr->top--;
        return val;
    }
}

int main()
{
    struct stack *sp = (struct stack *)malloc(sizeof(struct stack));
    sp->size = 10;
    sp->top = -1;
    sp->arr = (int *)malloc(sp->size * sizeof(int));
    printf("Stack has been created successfully\n");
    printf("Before Pushing,Full:%d\n", isFull(sp));
    printf("Before Pushing,Empty:%d\n", isEmpty(sp));
    push(sp, 1);
    printf("After Pushing,Full:%d\n", isFull(sp));
    printf("After Pushing,Empty:%d\n", isEmpty(sp));

    printf("poped %d from the stack\n", pop(sp)); // Last in First Out
    return 0;
}
