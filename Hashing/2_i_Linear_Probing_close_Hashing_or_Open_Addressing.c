#include <stdio.h>
#include <stdlib.h>

#define SIZE 10

int hash(int key)
{
    int index = key % SIZE; //get remainder as a location(index)
    return index;
}
int LinearProb(int key, int H[])
{
    int index = hash(key);
    int i = 0;
    while (H[(index + i) % SIZE] != 0)
        i++;
    return (index + i) % SIZE;
}
int insert(int key, int H[])
{
    int index = hash(key);
    if (H[index] != 0) //Here Happen Collusion.
        index = LinearProb(key, H);
    H[index] = key;
}
int search(int key, int H[])
{
    int index = hash(key);
    int i = 0;
    while (H[(index + i) % SIZE] != key)
        i++;
    return (index + i) % SIZE;
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
{ /*
     Note:Load Factor <= 0.5(only used half space of hashtable for store ele)
     
     number of ele(m)=5,memory blocks(size)=10
     Ex.
     LF =m/size =5/10 =0.5 (allow at most 5 ele)
     LF =m/size =6/10 =0.6 (Not allow 6 ele)
     LF =m/size =7/10 =0.7 (Not allow 7 ele)
     
     */

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