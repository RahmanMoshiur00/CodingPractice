#include<stdio.h>
int main()
{
    int n, i, N, mid;
    scanf("%d", &n);
    printf("Enter your respective number:\n");
        scanf("%d", &N);
    int array[n];
    for(i=0; i<n; i++){
        scanf("%d", &array[i]);
    }
    while(i<=n){
        mid = ( i + n ) / 2;
        if(N == array[mid]){
            break;
        }
        if(N > array[mid]){
            i = n + 1;
        }
        else{
            i = n - 1;
        }
    }
    printf("%d is founfd in the array", mid);
}

