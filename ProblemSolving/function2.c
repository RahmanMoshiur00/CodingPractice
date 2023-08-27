#include<stdio.h>
double add(double a, double b)
{
    double sum = a + b;
    return sum;
}

int main()
{
    double a, b, c;
    scanf("%lf%lf", &a, &b);
    c = add(a, b);
    printf("%.3lf + %.3lf = %.3lf", a, b, c);
}
