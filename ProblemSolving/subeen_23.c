#include<stdio.h>
int main()
{
    int l,t;
    scanf("%d", &t);
    for(l=0; l<t; l++){
        char arr[101];
        if(l==0) gets(arr);
        gets(arr);
        int i;
        for(i=0; arr[i]!=0; i++){
            printf("%d", arr[i]-'A'+1);
        }
        printf("\n");
    }
    return 0;
}
