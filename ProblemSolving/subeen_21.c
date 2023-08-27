#include<stdio.h>
#include<string.h>
int main()
{
    int t, l;
    scanf("%d", &t);
    for(l=0; l<t; l++){
        char arr[1001];
        gets(arr);
        if(l==0) gets(arr);
        int i, j;
        for(i=0, j=strlen(arr)-1; i<strlen(arr)/2; i++, j--){
            char a = arr[i];
            arr[i] = arr[j];
            arr[j] = a;
        }
        printf("%s\n", arr);
    }
    return 0;
}
