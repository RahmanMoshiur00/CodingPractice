#include<stdio.h>
#include<string.h>

int main()
{
    int i, counts=0, countb=0;
    char arr[100], arr2[100];
    gets(arr);
    gets(arr2);

    strcat(arr, arr2);
    printf("%s", arr);

}
