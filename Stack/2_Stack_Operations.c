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
        return 1;
    else
        return 0;
}
int isFull(struct stack *ptr)
{
    if (ptr->top == ptr->size - 1)
        return 1;
    else
        return 0;
}
void push(struct stack * ptr,int value){
    if (isFull(ptr))
    {
        printf("Stack is Overflow !\n");
    }
    else{
        ptr->top++;
        ptr->arr[ptr->top] = value;
        // printf("Value is Successfuly inserted .\n");
    }
}

int pop(struct stack *ptr){
    if(isEmpty(ptr)){
        printf("Stack Underflow !\n");
    }
    else{
        int value = ptr->arr[ptr->top];
        ptr->top--;
        return value;
    }
}

int main()
{
    struct stack *sp = (struct stack *)malloc(sizeof(struct stack));

    sp->size = 10;
    sp->top = -1;
    sp->arr = (int *)malloc(sp->size * sizeof(int));
    printf("Before pushing an element :is stack Empty? : %d\n", isEmpty(sp));
    printf("Before pushing an element :is stack Full ?: %d\n", isFull(sp));
    push(sp,0);
    push(sp,1);
    push(sp,2);
    push(sp,3);
    push(sp,4);
    push(sp,5);
    push(sp,6);
    push(sp,7);
    push(sp,8);
    push(sp,9);// stack is full
    // push(sp,10);// stack overflow
    
    printf("element : %d is poped !\n", pop(sp));
    printf("element : %d is poped !\n", pop(sp));
    printf("element : %d is poped !\n", pop(sp));
    printf("element : %d is poped !\n", pop(sp));
    printf("element : %d is poped !\n", pop(sp));
    printf("element : %d is poped !\n", pop(sp));
    printf("element : %d is poped !\n", pop(sp));
    printf("element : %d is poped !\n", pop(sp));
    printf("element : %d is poped !\n", pop(sp));
    printf("element : %d is poped !\n", pop(sp));
    printf("element : %d is poped !\n", pop(sp));
    
    printf("Aftore pushing an element :is stack Empty? : %d\n", isEmpty(sp));
    printf("Aftore pushing an element :is stack Full ?: %d\n", isFull(sp));

    return 0;
}