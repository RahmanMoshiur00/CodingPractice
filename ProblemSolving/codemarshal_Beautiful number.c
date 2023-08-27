#include<stdio.h>
int main()
{
    int t, i;
    scanf("%d", &t);
    for(i=1; i<=t; i++){
        unsigned long p, m[25], n, j, k, count=0;
        scanf("%lu", &p);
        for(j=0; j<p; j++){
            scanf("%lu", &m[j]);
        }
        scanf("%lu", &n);
        for(j=1; j<=n; j++){
            for(k=0; k<p; k++){
                if(j%m[k]==0){
                    count++;
                    break;
                }
            }
        }
        printf("%lu\n", count);
    }
    return 0;
}
