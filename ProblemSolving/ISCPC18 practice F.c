#include<stdio.h>
#include<math.h>

int main()
{
    int t, tc;
    scanf("%d", &tc);

    for(t = 1; t<=tc; t++){
        double c, d;

        scanf("%lf", &c);

        d = c / acos(-1.0);

        printf("Case %d: %.3lf\n", t, d);
    }

}
