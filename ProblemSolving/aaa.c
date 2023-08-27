#include<stdio.h>

int main()
{
    int t, l;
    scanf("%d", &t);

    for(l=1; l<=t; l++){
        long long a, b, c;

        scanf("%lld %lld %lld", &a, &b, &c);
        int count=0;

        if(a/b==c){
            //printf("/");
            count++;
        }
        if(a*b==c){
            //printf("*");
            count++;
        }
        if(a+b==c){
            //printf("+");
            count++;
        }
        if(a-b==c){
            //printf("-");
            count++;
        }

        int mark=0;

        if(a/b==c){
            printf("/");
            if(++mark!=count) printf(" ");
        }
        if(a*b==c){
            printf("*");
            if(++mark!=count) printf(" ");
        }
        if(a+b==c){
            printf("+");
            if(++mark!=count) printf(" ");
        }
        if(a-b==c){
            printf("-");
            if(++mark!=count) printf(" ");
        }

        printf("\n");
        //else printf("\n\n");
    }
    return 0;
}
