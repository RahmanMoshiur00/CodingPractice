#include<stdio.h>
#include<stdlib.h>
#include<math.h>
int main()
{
    int t, l;
    scanf("%d", &t);
    for(l=1; l<=t; l++){
        int p, k, d, i;
        scanf("%d %d %d", &p, &k, &d);
        /*double ans = (double)k / (double)d;
        int a = (int) ceil(ans);
        printf("Case %d: %d\n", l, p+(a*d));
        */
        for(i=1; ;i++){
            if((d*i)>k){
                printf("Case %d: %d\n", l, (d*i)+p);
                break;
            }
        }
    }
    return 0;
}
