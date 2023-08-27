#include<stdio.h>
#include<string.h>

int main()
{
    int t;
    scanf("%d", &t);
    while(t--){
        char num[101];
        scanf("%s", num);
        if((num[strlen(num)-1] - '0') % 2 == 0) printf("even\n");
        else printf("odd\n");
    }
    return 0;
}
