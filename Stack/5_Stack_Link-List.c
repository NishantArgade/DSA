
// Implementing Stack using Link-List
#include <stdio.h>
#include <stdlib.h>
struct Node{
    int data;
    struct Node * next;
};
struct Node * top;  // declare global
int isFull(struct Node *head){
    struct Node * nNode_ptr = (struct Node *)malloc(sizeof(struct Node ));
    if (nNode_ptr == NULL)
    {
        return 1;
    }
    else
     return 0;
    
}
int isEmpty(struct Node *head){
    // struct Node * n = (struct Node *)malloc(sizeof(struct Node ));
    if (head == NULL)
    {
        return 1;
    }
    else
     return 0;
    
}
struct Node * push(struct Node * top,int data){// Here Top means Head(Linklist)
   if (isFull(top))
   {
       printf("Stack is Overflow!\n");
   }
   else{
       struct Node *ptr =(struct Node *)malloc(sizeof(struct Node));
       ptr->data = data;
       ptr->next = top;
       top = ptr;
       return top;
   } 
}
int pop(struct Node * top){
   if (isEmpty(top))
   {
       printf("Stack is Underflow!\n");
   }
   else{
       struct Node *ptr = top;
       int data= top->data;
       top = top->next;
       free(ptr);
       return data;
   } 
}

int peek(struct Node *ptr,int position){
   for (int i = 1; i < position; i++)
   {
       ptr = ptr->next;
   }
    if (position == 1)
   {
      return ptr->data;
   }
   
   else if (ptr != NULL)
   {
       return ptr->data;
   }
   else
     return -1;
   
}
int StackTop(struct Node *ptr){
    return ptr->data;
}
int StackBottom(struct Node *ptr){
    struct Node * temp = ptr;
    while(temp->next != NULL){
        temp = temp->next;
    }
    return temp->data;
}
void LinkList_Traverser(struct Node *ptr){
    while (ptr != NULL)
    {
        printf("%d\n",ptr->data);
        ptr = ptr->next;
    }
    
}
int main()
{	struct Node * top =NULL;// top == head(Linklist)
    top =push(top,30);
    top =push(top,50);
    top =push(top,45);
    top =push(top,7);
    top =push(top,95);
    top =push(top,88);
    top =push(top,23);
    top =push(top,100);
    // LinkList_Traverser(top);
    // int pop_data= pop(top);
    // printf("The popped out node is : %d\n",pop_data);
    for (int i = 1; i < 7; i++)
    {
    int peek_data = peek(top,i);
    printf("The %d peek Data is %d\n",i,peek_data);
        
    }
    printf("The stack Top is : %d\n",StackTop(top));
    printf("The stack Bottom is : %d\n",StackBottom(top));
    
    
    return 0;
}