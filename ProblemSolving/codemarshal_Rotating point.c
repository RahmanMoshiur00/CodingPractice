#include<stdio.h>
int main()
{
    unsigned int t, l;
    scanf("%u", &t);
    for(l=1; l<=t; l++){
        long long int x, y, theta;
        scanf("%lld %lld %lld", &x, &y, &theta);
        if(theta==90){
            int temp = x;
            x = -1*y;
            y = temp;
            printf("Case %u: %.3lf %.3lf\n", l, (double)x, (double)y);
        }
        else if(theta==180){
            x = -1*x;
            y = -1*y;
            printf("Case %u: %.3lf %.3lf\n", l, (double)x, (double)y);
        }
        else if(theta==270){
            int temp = y;
            y = -1*x;
            x = temp;
            printf("Case %u: %.3lf %.3lf\n", l, (double)x, (double)y);
        }
        else if(theta==0 || theta==360) printf("Case %u: %.3lf %.3lf\n", l, (double)x, (double)y);
    }
    return 0;
}
