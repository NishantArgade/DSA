#include <stdio.h>
#include <stdlib.h>

#define SIZE 10

struct LLnode
{
    int val;
    struct LLnode *next;
};
struct LLnode *head[SIZE] = {NULL}, *ptr;
int hash(int key)
{
    int index = key % SIZE; //get remainder as a location(index)
    return index;
}

int insert(int key)
{
    struct LLnode *newNode;
    newNode = (struct LLnode *)malloc(sizeof(struct LLnode));
    newNode->val = key;
    newNode->next = NULL;

    int index = hash(key);
    if (head[index] == NULL)
        head[index] = newNode;
    else
    {
        struct LLnode *curr, *prev;
        prev = head[index];
        curr = head[index];
        while (curr && curr->val < key)
        {
            prev = curr;
            curr = curr->next;
        }
        if (prev == curr)
        {
            newNode->next = prev;
            head[index] = newNode;
        }
        if(prev != curr)
        {
            newNode->next = prev->next;
            prev->next = newNode;
        }
    }
}
int search(int key)
{
    int index = hash(key);
    int i = 0;
    if (head[index] == NULL)
        printf("Element is not Found !\n");
    else
    {
        ptr = head[index];
        for (; ptr != NULL; ptr = ptr->next)
        {
            if (ptr->val == key)
            {
                printf("Element is Found \n");
                break;
            }
        }
        if (ptr == NULL)
            printf("Element is not Found !\n");
    }
}
void Display()
{
    for (int i = 0; i < SIZE; i++)
    {
        if (head[i] == NULL)
            continue;
        else
        {
            ptr = head[i];
            for (; ptr != NULL; ptr = ptr->next)
            {
                printf("--> %d", ptr->val);
            }
        }
        printf("\n");
    }
}
int main()
{ 
    //Note:Here don't Happen Collusion.

    insert(72);
    insert(18);
    insert(12);
    insert(124);
    insert(22);
    insert(88);
    insert(24);
    insert(14);
    insert(17);

    search(124);
    
    Display();

    return 0;
}