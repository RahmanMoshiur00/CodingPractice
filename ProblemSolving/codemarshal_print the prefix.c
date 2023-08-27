#include<stdio.h>
#include<string.h>

int main()
{
    int t, i;
    scanf("%d", &t);
    for(i=1; i<=t; i++){
        char str[201];
        int j, k;
        scanf("%s", str);
        printf("Case %d:\n", i);
        for(j=0; j<strlen(str); j++){
            for(k=0; k<=j; k++) printf("%c", str[k]);
            printf("\n");
        }
    }
}
