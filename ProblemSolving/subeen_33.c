#include<stdio.h>
int main()
{
    long long a, b, c, i, start;
    scanf("%lld %lld %lld", &a, &b, &c);
    for(i=a; ; i++){
        if(i%c==0){
            start = i;
            break;
        }
    }
    for(i=start; i<=b; i += c) printf("%lld\n", i);
    return 0;
}
