#include <stdio.h>
#include <stdlib.h>

#define SIZE 10

int hash(int key)
{
    int index = key % SIZE; //get remainder as a location(index)
    return index;
}
int QuadraticProb(int key, int H[])
{
    int index = hash(key);
    int i = 0;
    while (H[(index + i * i) % SIZE] != 0)
        i++;
    return (index + i * i) % SIZE;
}
int insert(int key, int H[])
{
    int index = hash(key);
    if (H[index] != 0)             //Here Happen Collusion.
        index = QuadraticProb(key, H);
    H[index] = key;
}
int search(int key, int H[])
{
    int index = hash(key);
    int i = 0;
    while (H[(index + i * i) % SIZE] != key)
        i++;
    return (index + i * i) % SIZE;
}
void Display(int H[])
{
    printf("\nHashtable:\n");

    for (int i = 0; i < SIZE; i++)
    {
        printf("%d\n", H[i]);
    }
}
int main()
{  
    int H[10] = {0};

    insert(35, H);
    insert(18, H);
    insert(12, H);
    insert(22, H);
    insert(17, H);

    Display(H);

    printf("Element is found at index : %d\n", search(22, H));

    return 0;
}