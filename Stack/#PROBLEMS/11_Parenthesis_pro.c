// Implementing Stack using Array
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
void push(struct stack* ptr, char val){
        ptr->top++;
        ptr->arr[ptr->top] = val;
}

void pop(struct stack* ptr){
        char val = ptr->arr[ptr->top];
        ptr->top--;
}

int IsparenthesisMatch(char *exp)
{
    //Create and  initialize  the stack
    struct stack *sp;
    sp->size = strlen(exp);
    sp->top = -1;
    sp->arr = (char *)malloc(sp->size * sizeof(char));

    for (int i = 0; exp[i] != '\0'; i++)
    {
        if (exp[i] == '(')
        {
            push(sp, '(');
        }
        else if (exp[i] == ')')
        {
            if (isEmpty(sp))
            {
                return 0;
            }
            pop(sp);
        }
    }
        if (isEmpty(sp))
        {
            return 1;
        }
        else{
            return 0;
        }
}

int main()
{
    char *exp = ")(2+3)*(5*8)(445)";// *pinter point to the string

    if (IsparenthesisMatch(exp))
        printf("The Parenthesis is Match.");
    else
        printf("The Parenthesis is not Match ! ");
    return 0;
}