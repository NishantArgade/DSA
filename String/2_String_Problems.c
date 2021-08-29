#include <stdio.h>
#include <stdlib.h>

void ChangCase(char C[])
{
    for (int i = 0; C[i] != '\0'; i++)
    {
        if (C[i] >= 65 && C[i] <= 90)
            // For Capital char
            C[i] = C[i] + 32;

        else if (C[i] >= 'a' && C[i] <= 122)
            // For small Char
            C[i] = C[i] - 32;
    }
}
void CountingVowels_Consonent(char C[])
{
    int Vcount = 0;
    int Ccount = 0;

    for (int i = 0; C[i] != '\0'; i++)
    {
        if (C[i] == 'a' || C[i] == 'e' || C[i] == 'i' || C[i] == 'o' || C[i] == 'u' || C[i] == 'A' || C[i] == 'E' || C[i] == 'I' || C[i] == 'O' || C[i] == 'U')
        {
            Vcount++; // For Capital char
        }
        else if (C[i] >= 65 && C[i] <= 90 || C[i] >= 'a' && C[i] <= 122)
            Ccount++; // For Capital char
    }
    printf("The vowels are : %d\n", Vcount);
    printf("The Consonent are : %d\n", Ccount);
}
void Countingwords(char C[])
{
    int word = 1;

    for (int i = 0; C[i] != '\0'; i++)
    {
        if (C[i] == ' ' && C[i - 1] != ' ')
            word++; // For Capital char
    }
    printf("The words are : %d\n", word);
}
int isValidString(char C[])
{
    int word = 0;

    for (int i = 0; C[i] != '\0'; i++)
    {
        if (!(C[i] >= 65 && C[i] <= 90) && !(C[i] >= 'a' && C[i] <= 122) && !(C[i] >= 48 && C[i] <= 57))
            return 0;
    }
    return 1;
}
void ReverseString(char C[])
{
    int word = 0, i, j;
    for (i = 0; C[i] != '\0'; i++)
    {
    }
    char B[i];
    i = i - 1;
    for (j = 0; i >= 0; j++, i--)
    {
        B[j] = C[i];
    }
    B[j] = '\0';
    printf("%s\n", B);
}
void ReverseString2(char C[])
{
    int word = 0, i, j;
    for (i = 0; C[i] != '\0'; i++)
    {
    }
    i = i - 1;
    for (j = 0; j < i; j++, i--)
    {
        int temp = C[j];
        C[j] = C[i];
        C[i] = temp;
    }
    printf("%s\n", C);
}
void Compare2Strings(char B[], char C[])
{
    int i, j;
    for (i = 0, j = 0; B[i] != '\0' && C[j] != '\0'; i++, j++)
    {
        if (B[i] != C[j])
            break;
    }
    if (B[i] == C[j])
        printf("Equal\n");
    else if (B[i] < C[j])
        printf("smaller\n");
    else
        printf("Greater\n");
}
int isPalindrome(char C[])
{
    int i, j;
    for (i = 0; C[i] != '\0'; i++)
    {
    }
    i = i - 1;
    for (j = 0; j < i; j++, i--)
    {
        if (C[j] != C[i])
            return 0;
    }
    return 1;
}
void Dublicate(char C[])
{
    int i, j;
    int H[26] = {0};
    for (i = 0; C[i] != '\0'; i++)
    {
        H[C[i] - 97] += 1;
    }

    for (j = 0; j < 26; j++)
    {
        if (H[j] > 1)
        {
            printf("%c\n", j + 97);
            printf("%d\n", H[j]);
        }
    }
}
void isAnagram(char A[],char B[])
{
    int i, j;
    int H[26] = {0};

    for (i = 0; B[i] != '\0'; i++)
        H[B[i] - 97] += 1;

    for (i = 0; A[i] != '\0'; i++)
        H[A[i] - 97] -= 1;

    for (j = 0; j < 26; j++)
    {
        if (H[j] < 0)
        {
            printf("is not anagram !\n");
            break;
        }
    }
    if (j == 26)
        printf("is anagram \n");
}
void perm(char S[], int k)
{
    static char A[10] = {0};
    static char Result[10];
    int i, j;

    if (S[k] == '\0')
    {
        if (Result[k] == '\0')
            printf("permutaton => %s \n", Result);
    }
    else
    {
        for (i = 0; S[i] != '\0'; i++)
        {
            if (A[i] == 0)
            {
                Result[k] = S[i];
                A[i] = 1;
                perm(S, k + 1);
                A[i] = 0;
            }
        }
    }
}
int main()
{
    char C[] = "abeccHHGD";
    char B[] = "abe3?HGD";

    // ChangCase(C);
    // CountingVowels_Consonent(C);
    // Countingwords(C);

    // char C1[] = "abecc HHGD";//(NOt valid string if ' ',( )/?!@#$%^&&*.)
    // printf("is Valid String : %d\n",isValidString(C1));

    // Compare2Strings(B, C);

    // char P[] = "madam";
    // printf(" %d\n", isPalindrome(P));

    // Dublicate(C);

    // char X[] = "decimal";
    // char Y[] = "medical";
    // isAnagram(X,Y);

    char A[] = "ABC";
    perm(A, 0);//posible Arrangment( n! )

    return 0;
}