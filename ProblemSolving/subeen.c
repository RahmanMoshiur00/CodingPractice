#include<stdio.h>
#include<math.h>

int main()
{
    int t, l;
    scanf("%d", &t);

    double ans = t/10.00;

    if(ans + 0.50 > (int)ans){
        ans = ceil(ans);
        ans *= 10;
    }
    else ans = floor(ans);

    printf("%.0lf\n", ans);

    return 0;
}
