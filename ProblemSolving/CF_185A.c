#include <stdio.h>
#include<math.h>

int main(){
    unsigned long long n;
    scanf("%lld", &n);
    double N = n * 1.0;
    unsigned long long res = (unsigned long long)((unsigned long long)(pow(2.0, N) * (unsigned long long)(pow(2.0, N)+1)) / 2);
    printf("%llu\n", res%1000000007);

    return 0;
}


