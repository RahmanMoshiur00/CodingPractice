#include<stdio.h>
int main()
{
    long long int a, b, t, i, j;
    scanf("%lld", &t);

    for(i=1; i<=t; i++){
        scanf("%lld %lld", &a, &b);

        long long int t;
        if(a==0) printf("%lld\n", a);
        else if(b == 0) printf("%lld\n", b);
        else{
            while(a != 0){
                t = a;
                a = b % a;
                b = t;
            }
            printf("%lld\n", b);
        }
    }

    return 0;
}
