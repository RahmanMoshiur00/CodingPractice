#include <stdio.h>
#include <math.h>

int main()
{
    long long int a, b, c;

    int tc;
    scanf("%d", &tc);

    while(tc--){
        scanf("%lld %lld %lld", &a, &b, &c);

        double s, res , ans;

        if((a+b >= c) && (a+c >= b) && (b+c >= a)){
            s = (double)(a+b+c) / 2.0;
            res = s * (s-a) * (s-b) * (s-c);
            ans = sqrt(res);
            printf("%.2lf\n", ans);
        }
        else{
            printf("Oh, No!\n");
        }
    }

    return 0;
}
