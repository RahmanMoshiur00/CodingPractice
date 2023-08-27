#include<stdio.h>
#include<math.h>

int main()
{
    int t, l;
    scanf("%d", &t);
    for(l=0; l<t; l++){
        int R, n;
        double r, val;
        scanf("%d %d", &R, &n);
        if(R>=1 && R<=1000 && n>=3 && n<=100){
            double pi = 2 * acos(0.0);
            val = pi / 180.0;
            r = (R*sin((180.0*val)/(n*1.0))) / (1.0+sin((180.0*val)/(n*1.0)));
            printf("%.2lf\n", r);
        }
    }
    return 0;
}
