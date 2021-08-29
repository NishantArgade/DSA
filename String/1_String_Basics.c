#include <stdio.h>
#include <stdlib.h>
int sizeofString(char *S)
{
    int i;
    for (i = 0; S[i] != '\0'; i++)
    {
    }
    return i;
}
int main()
{
    //Decimal value of integer is=>
    printf("%d\n", '0'); // 48
    printf("%d\n", '1'); //49
    printf("%d\n", '2'); //50 so on......up to(9) 57.

    //Decimal value of Capital char is =>
    printf("%d\n", 'A'); // 65
    printf("%d\n", 'B'); //66
    printf("%d\n", 'C'); //67 so on......up to(Z) 90.

    //Decimal value of Small char is=>
    printf("%d\n", 'a'); // 97
    printf("%d\n", 'b'); //98
    printf("%d\n", 'c'); //99 so on......up to (z)122.

    // Representaion of Charactor Array:
    char C1[5];                   //Declare(store in internal stack)
    char C2[5] = {'a', 'b', 'c'}; //Declare + initialization(store in internal stack)
    char C3[] = {'a', 'b', 'c'};  //Declare + initialization(store in internal stack)

    printf("%c\n", C1[0]);
    printf("%c\n", C2[1]);
    printf("%c\n", C3[2]);
    printf("The size of String is : %d\n", sizeof(C3) / sizeof(C3[0]));

    // Representaion of String in  Array:
    // Note That: String Always Terminate with NULL Chatactor=>'\0' in C and C++.

    char S1[] = {'a', 'b', 'c', '\0'}; //Declare + initialization(store in internal stack)
    char S2[] = "Coder";               //terminate with:'\0'        //Declare + initialization(store in internal Stack)
    char *S3 = "Nishant";              //terminate with:'\0'         //Declare + initialization(store in internal Heap)
    char *S4 = "How are you";          //terminate with:'\0'        //Declare + initialization(store in internal Heap)
    //---------------------------------------------|.
    //      |H|o|w|   |a|r|e|   |y|o|u|\0|         |.
    //       0 1 2  3  4 5 6  7  8 9 10 11         |.
    //---------------------------------------------|.
    printf("%s\n", S2);
    printf("%s\n", S3);
    printf("%s\n", S4);
    printf("The size of String is : %d\n", sizeofString(S1));

    return 0;
}