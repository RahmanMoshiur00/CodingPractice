#include<stdio.h>
int main()
{
    int t, l;
    scanf("%d", &t);
    for(l=1; l<=t; l++){
        long long n;
        scanf("%lld", &n);
        long long num[n], count=0;
        int i;
        for(i=0; i<n; i++) scanf("%lld", &num[i]);

        long long int max = num[0];
        for(i=1; i<n; i++){
            if(num[i]>max){
               max = num[i];
            }
        }
        for(i=0; i<n; i++){
            if(max==num[i]) count++;
        }
        printf("Case %d: %lld\n", l, count);
        getchar();
        printf("");
    }
}
