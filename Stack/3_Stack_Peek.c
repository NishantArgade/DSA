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

int peek(struct stack *sp,int position){//  position  |     index
    int arrayInd = sp->top-position +1; //     1    ele3 <--   2 <= Top
    if (arrayInd <0)              //           2    ele2 <--   1
     {                           //            3    ele1 <--   0
        printf("Invalid position input !\n");//      0        -1 <= No ele
        return -1;
    }
    else{
        return sp->arr[arrayInd];
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
    push(sp,9);// stack is full // Stack Follow LIFO 
    // push(sp,10);// stack overflow
    
    // printf("element : %d is poped !\n", pop(sp));
    // peek(sp,5);
    printf("%d\n",peek(sp,1));
    printf("Aftore pushing an element :is stack Empty? : %d\n", isEmpty(sp));
    printf("Aftore pushing an element :is stack Full ?: %d\n", isFull(sp));

    return 0;
}