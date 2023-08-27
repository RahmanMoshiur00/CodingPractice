#include<math.h>

int main()
{
    int t, l;
    scanf("%d", &t);
    for(l=1; l<=t; l++){
        double r;
        int n;
        scanf("%lf %d", &r, &n);
        double pi = 2*acos(0.0);
        //r = Rsin(π/n)/[1 + sin(π/n)] **that's the theory
        printf("Case %d: %.10lf\n", l, (r*sin(pi/n)) / (1+sin(pi/n)));
    }
}
