#include<stdio.h>

int main()
{
    long long i, n, q, h, j;
    scanf("%lld", &n);

    long long hite[n];

    for(i=0; i<n; i++) scanf("%lld", &hite[i]);
    printf("");
    scanf("%lld", &q);
    printf("");
    int que[q];

    for(i=0; i<q; i++) scanf("%d", &que[i]);
    int mark;
    for(i=0; i<q; i++){
            mark=0;
        for(j=n-1; j>=0; j--){
            if(que[i]==hite[j]){
                mark = 1;
                break;
            }
        }
        if(mark==0) printf("-1\n");
        else printf("%lld\n", j+1);
    }

    return 0;
}
