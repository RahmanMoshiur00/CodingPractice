#include<stdio.h>
int main()
{
    int t, i;
    scanf("%d", &t);
    for(i=1; i<=t; i++){
        int n, j, k;
        scanf("%d", &n);
        long long int rate[n], count=n;
        for(j=0; j<n; j++){
            scanf("%lld", &rate[j]);
        }
        for(j=0; j<n; j++){
            if(rate[j]<=1000000000000){
                for(k=j+1; k<n; k++){
                    if(rate[j]==rate[k]){
                        rate[k] = 10000000000000;
                        count--;
                    }
                }
            }
        }

        printf("Case %d: %lld\n", i, count);
    }
}
