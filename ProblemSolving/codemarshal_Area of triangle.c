#include<math.h>
main()
{
    int t, i, a, b, c;
    double area;
    scanf("%d", &t);

    for(i=1; i<=t; i++){
        scanf("%d %d %d", &a, &b, &c);
        if((a+b>=c) || (a+c>=b) || (b+c>=a)){
            double s = (a+b+c)/2.0;
            printf("Case %d: %.10lf\n", i, sqrt(s*(s-a)*(s-b)*(s-c)));
        }
    }
}
