#include<stdio.h>

int main()
{
    int t, l;
    scanf("%d", &t);

    for(l=1; l<=t; l++){
        int n, x, y;
        scanf("%d %d %d", &n, &x, &y);
        int a[x], b[y], mark[n], k=0, i, j;

        for(i=0; i<x; i++) scanf("%d", &a[i]);
        for(i=0; i<y; i++) scanf("%d", &b[i]);

        for(i=1; i<=n; i++){
            for(j=0; j<x; j++){
                if(i%a[j]==0){
                    mark[k++] = i;
                    break;
                }
            }
        }
        int count = k;
        for(i=0; i<k; i++){
            for(j=0; j<y; j++){
                if(mark[i]%b[j]==0){
                    count--;
                    break;
                }
            }
        }
        printf("%d\n", count);
    }

    return 0;
}
