#include<stdio.h>
int main()
{
    int a, b, i, count=0;
    scanf("%d %d", &a, &b);
    for(i=1; i<=b; i++){
        printf("%d", i);
        count++;
        if(count==a){
            printf("\n");
            count=0;
        }
        else printf(" ");

    }

}
