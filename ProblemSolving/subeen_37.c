#include<stdio.h>
#include<string.h>
int main()
{
    int t;
    scanf("%d", &t);
    scanf(" ");
    while(t--){
        char num[10];
        int i;
        scanf("%s", num);
        for(i=strlen(num)-1; i>=0; i--) printf("%c", num[i]);
        printf("\n");
    }
    return 0;
}
