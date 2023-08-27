#include<stdio.h>
int main()
{
    long long n, k, i, count=0;
    scanf("%lld %lld", &n, &k);
    for(i=1; i<=n; i++){
        if(n%i==0) count++;
        if(count==k){
            printf("%lld\n", i);
            goto end;
        }
    }
    printf("-1\n");
    end:
        printf("");
    return 0;
}
