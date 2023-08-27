#include<stdio.h>
int main()
{
    int t;
    scanf("%d", &t);
    while(t--){
        int a, b, gcd, i;
        scanf("%d %d", &a, &b);
        if(a>b){
            int c = a;
            a = b;
            b = c;
        }

        if(a==b) gcd = a;
        else if(a==0) gcd = b;

        for(i=a; i>=1; i--){
            if(a%i==0 && b%i==0){
                gcd = i;
                break;
            }
        }
        printf("LCM = %d\n", (a*b)/gcd);
    }
    return 0;
}

