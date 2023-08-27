#include<stdio.h>
#include<stdio.h>
int main()
{
    int n;

    while(scanf("%d", &n) && n!=0){
        int i, j;
        double x[n], y[n];
        for(i=0; i<n; i++){
            scanf("%lf %lf", &x[i], &y[i]);
        }
        double xmin, xmax, ymin, ymax;
        xmax = x[0];
        for(i=1; i<n; i++){
            if(x[i]>xmax) xmax = x[i];
        }
        xmin = x[0];
        for(i=1; i<n; i++){
            if(x[i]<xmin) xmin = x[i];
        }
        ymax = y[0];
        for(i=1; i<n; i++){
            if(y[i]>ymax) ymax = y[i];
        }
        ymin = y[0];
        for(i=1; i<n; i++){
            if(y[i]<ymin) ymin = y[i];
        }
        double res = (xmax-xmin)*(ymax-ymin);
        printf("%.4lf\n", res);
    }
    return 0;
}
