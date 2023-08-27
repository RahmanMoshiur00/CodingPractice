#include<stdio.h>
int main()
{
    int t, l;
    long long min = 1, max = 1, x, x1=1;
    double res;
    scanf("%d", &t);
    for(l=1; l<=t; l++){
        scanf("%lld", &x);
        if(l==1){
            max = x;
            min = x;
            res = (double)max / (double)min;
            printf("Case %d: %.2lf\n", l, res);
        }
        else{
            if(x<min) min = x;
            if(x>max) max = x;
            res = (double)max / (double)min;
            printf("Case %d: %.2lf\n", l, res);
        }
    }
}
