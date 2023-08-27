#include<stdio.h>

int main()
{
    int t, l;
    scanf("%d", &t);
    for(l=1; l<=t; l++){
        int div[1001] = {0};
        int i, j;

        for(i=1; i<=1000; i++){
            for(j=1; j<=i; j++){
                if(i%j==0){
                    div[i]++;
                }
            }
        }

        int ans[1001] = {0};
        int k = 1;

        for(i=1; i<=32; i++){
            for(j=1000; j>=1; j--){
                if(i==div[j]){
                    ans[k] = j;
                    k++;
                }
            }
        }

        int Case;
        scanf("%d", &Case);
        printf("Case %d: %d\n", l, ans[Case]);

    }
    return 0;
}
