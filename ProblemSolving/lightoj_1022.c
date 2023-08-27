#include<math.h>
main()
{
    int t, j;
    scanf("%d", &t);
    for(j=1; j<=t; j++){
        double pi = 2 * acos(0.0);
        double r;
        scanf("%lf", &r);
        printf("Case %d: %.2lf\n", j, 4*r*r - pi*r*r);
    }
}
