//finding nth palindrome number from 1
#include<stdio.h>

int checkPal(int a)
{
    int i;
    char arr[15];
    sprintf(arr, "%d", a);
    for(i=0; i<strlen(arr)/2; i++){
        if(arr[i] != arr[strlen(arr)-1-i]){
            return 0;
        }
    }
    return 1;
}

int main()
{
    int n, i, j=0, nPal=0;
    scanf("%d", &n);
    int palindromes[n];

    for(i=1; ; i++){
        if(checkPal(i)==1){
            nPal++;
            palindromes[j++] = i;
        }
        if(nPal==n) break;
    }

    for(i=0; i<n; i++) printf("%d ", palindromes[i]);

    return 0;
}
