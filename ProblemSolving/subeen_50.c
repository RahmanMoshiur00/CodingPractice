#include<stdio.h>
#include<string.h>
int main()
{
    int t;
    scanf("%d", &t);
    scanf(" ");
    while(t--){
        char arr[51];
        gets(arr);
        int i;
        for(i=0; i<strlen(arr); i++){
            if(arr[i]=='L') arr[i] = arr[i-1];
            else if(arr[i]=='R') arr[i] = arr[i+1];
        }
        printf("%s\n", arr);
    }
    return 0;
}
