/*81*/
#include<stdio.h>
int main()
{
    int r;
    printf("Enter radius of the circle:");
    scanf("%d", &r);
    int* p = &r;
    double A = (*p) * (*p) * 3.1416;
    printf("Area=%.2lf", A);
}
