#include<stdio.h>
#include<math.h>

int main()
{
    int l, t;
    scanf("%d", &t);
    for(l=1; l<=t; l++){
        long long u, a, s;
        scanf("%lld %lld %lld", &u, &a, &s);
        double temp = 0.0, ans = 0.0;
        temp = sqrt((u*u*1.0) + (a*a*1.0));
        ans = (double)s / (temp);
        printf("Case %d: %.6lf\n", l, ans);
    }
    return 0;
}
