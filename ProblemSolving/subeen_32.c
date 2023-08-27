#include<stdio.h>
int main()
{
    int t;
    scanf("%d", &t);
    while(t--){
        int a, b, i;
        scanf("%d %d", &a, &b);
        if(a>b) printf("Invalid!\n");
        else{
            for(i=a; i<=b; i+=a) printf("%d\n", i);
            printf("\n");
        }
    }
    return 0;
}
