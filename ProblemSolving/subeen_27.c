#include<stdio.h>
#include<stdlib.h>

int qube(int m){
    return m*m*m;
}

int main()
{
    int t, l;
    scanf("%d", &t);
    for(l=0; l<t; l++){
        char arr[4];
        gets(arr);
        if(l==0) gets(arr);
        int n, ans=0, i;

        for(i=0; i<strlen(arr); i++){
            ans += qube(arr[i] - '0');
        }
        n = atoi(arr);
        if(n==ans) printf("%d is an armstrong number!\n", n);
        else printf("%d is not an armstrong number!\n", n);
    }
    return 0;
}
