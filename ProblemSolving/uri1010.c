#include<stdio.h>
main()
{
    int code, unit, code1, unit1;
    float p, price, price1;
    scanf("%d%d%f", &code, &unit, &price);
    scanf("%d%d%f", &code1, &unit1, &price1);
    p = (unit*price) + (unit1*price1);
    printf("tk %.2f\n", p);
}
