/*79*/
#include<stdio.h>
int main()
{
    int i, j, temp, a[5];
    printf("Enter 5 integers to revers in an array:");
    for(i=0; i<5; i++) scanf("%d", &a[i]);
    for(i=0, j=4; i<5/2; i++, j--){
        temp = a[i];
        a[i] = a[j];
        a[j] = temp;
    }
    printf("After reversing the array:");
    for(i=0; i<5; i++) printf("%d ", a[i]);
}
