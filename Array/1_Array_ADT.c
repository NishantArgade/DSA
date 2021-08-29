// Array implementation :

// ADT( Abstract data type) => (Set of Values + set of Operaton.)used primitive data type (int ,float,char etc...) and make CUSTOM data type is called ADT .Used primitive data type without warry about their implimentation(hide their implimentation and only used they for make abstract data type) is called ADT.

//ex.Array ADT :
#include <stdio.h>
#include <stdlib.h>


struct Array_ADT
{
    int total_size;
    int used_size;
    int* ptr;
};

void creatArray(struct Array_ADT* a,int tSize,int uSize){
    // (*a)total_size =tSize;
    // (*a)used_size =uSize;
    // (*a)ptr =(int*)malloc(tSize*sizeof(int));
    a->total_size =tSize;
    a->used_size =uSize;
    a->ptr =(int*)malloc(tSize*sizeof(int));
}

void setValues(struct Array_ADT* a){

    printf("Enter values :\n");
    for (int i = 0; i < a->used_size; i++)
    {
        scanf("%d",&(a->ptr[i]));
    } 
}

void printValues(struct Array_ADT* a){

    printf("The  values  is :\n");
    for (int i = 0; i < a->used_size; i++)
    {
        printf("%d",(a->ptr[i]));
    } 
}

int main()
{	struct Array_ADT marks;

    creatArray(&marks,10,2);

    //Minimum required Operation:
    setValues(&marks);
    printValues(&marks);
    
    return 0;
}