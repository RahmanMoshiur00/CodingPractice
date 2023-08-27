#include<stdio.h>
#include<string.h>
int main()
{
    int t, l;
    scanf("%d", &t);
    for(l=0; l<t; l++){
        char arr[10001];
        int i, count=1;
        gets(arr);
        if(l==0) gets(arr);
        for(i=0; i<strlen(arr); i++){
            if(arr[i]==' ') count++;
        }
        printf("Count = %d\n", count);
    }
    return 0;
}
