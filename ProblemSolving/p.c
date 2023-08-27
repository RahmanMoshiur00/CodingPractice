#include<stdio.h>
#include<math.h>

int main()
{
    long long i, n, count=1, j;
    n = 9223372036854775806;

    for(i=1; i<=n; i++){
        count = 1;
        for(j=2; j<=sqrt(i); j++){
            if(j==i) break;
            if(count>i) break;
            else if(i%j==0){
                if(i/j==j) count += j;
                else count += j + (i/j);
            }

        }

        if(count==i) printf("%lld, ", i);
    }
    return 0;
}
