#include<stdio.h>
#include<math.h>

int main()
{
    int t, tc;
    scanf("%d", &tc);

    for(t = 1; t<=tc; t++){
        double x1, y1, x2, y2, d, x, y;

        scanf("%lf %lf %lf %lf", &x1, &y1, &x2, &y2);

        x = x1 - x2;
        y = y1 - y2;

        d = sqrt((x*x) + (y*y));

        printf("Case %d: %.4lf\n", t, d);
    }

}
