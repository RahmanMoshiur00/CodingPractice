/*46*/
#include<stdio.h>
int main()
{
    int n, i, find = 0, a[5];
    printf("Enter 5 integers in an array:");
    int size = sizeof(a) / sizeof(int);
    for(i=0; i<size; i++) scanf("%d", &a[i]);
    printf("Enter a number to search:");
    scanf("%d", &n);
    for(i=0; i<size; i++){
        if(a[i]==n) find = 1;
    }
    if(find==1) printf("%d is in the array", n);
    else printf("%d is not in the array", n);
}
