#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct stack
{
    int size;
    int top;
    char *arr;
};
int isEmpty(struct stack *ptr)
{
    if (ptr->top == -1)
        return 1;
    else
        return 0;
}
void push(struct stack *ptr, char value)
{
   
        ptr->top++;
        ptr->arr[ptr->top] = value;
        // printf("Value is Successfuly inserted .\n");
    
}
char pop(struct stack *ptr)
{
    if (isEmpty(ptr))
    {
        printf("Stack Underflow !\n");
    }
    else
    {
        char value = ptr->arr[ptr->top];
        ptr->top--;
        return value;
    }
}
int isOperetor(char cha)
{
    if (cha == '*' || cha == '/' || cha == '+' || cha == '-')
    {
        return 1;
    }
    else
        return 0;
}
int precedence(char cha)
{
    if (cha == '*' || cha == '/')
    {
        return 3;
    }
    if (cha == '+' || cha == '-')
    {
        return 2;
    }
    else
        return 0;
}
char top(struct stack *sp){
    return sp->arr[sp->top];
}

char *  Infix_TO_Postfix(char *infix)
{
    // initialize and creating the stack
    struct stack *sp=(struct stack*)malloc(sizeof(struct stack));// initialize stack
    sp->size = 100;
    sp->top = -1;
    sp->arr = (char *)malloc(sp->size * sizeof(char));

    // Dinamicaly creating postfix array
    char *postfix = (char *)malloc((strlen(infix)+ 1 )* sizeof(char));
    int i = 0;
    int j = 0;
    while (infix[i] != '\0')
    {
        if (!isOperetor(infix[i]))
        {
            postfix[j] = infix[i];
            j++;
            i++;
        }
        else if (precedence(infix[i]) > precedence(top(sp)))
        {
            push(sp, infix[i]);
            i++;
        }
        else
        {
            postfix[j] = pop(sp);
            j++;
        }
    }
    while (!isEmpty(sp))
    {
        postfix[j] = pop(sp);
        j++;
    }
        postfix[j] = '\0';

    return postfix;
}

int main()
{
    // infix to postfix conversion :
    char *exp = "2*3*5+5"; //Ans= postfix 23*4+
    printf("The Infix to postfix conversion is : %s", Infix_TO_Postfix(exp));
    return 0;
}