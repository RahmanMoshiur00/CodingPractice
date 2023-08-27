#include<stdio.h>

double find_max(double x, double y)
{
    if(x>y)
    return x;
    else{
        return y;
    }
}

int main()
{
    double a, b, c;
    scanf("%lf%lf", &a, &b);
    c = find_max(a, b);
    printf("max= %lf", c);
}
