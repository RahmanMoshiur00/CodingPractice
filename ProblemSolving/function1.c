#include<stdio.h>
double circle_khetrofol(double x, double y);

int main()
{
    double h, l, maan;

    printf("Enter the hieght of the circle:\n");
    scanf("%lf", &h);
    printf("Enter the length of the circle:\n");
    scanf("%lf", &l);

    maan = circle_khetrofol(h, l);
    printf("Circle Khetrofol=%.3lf\n", maan);

}

double circle_khetrofol(double a, double b)
{
    double o;
    o = 0.5 * a * b;
    return o;
}
