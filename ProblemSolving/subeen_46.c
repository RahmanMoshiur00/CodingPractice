#include<stdio.h>
int main()
{
    int t;
    scanf("%d", &t);
    while(t--){
        int a, b, c;
        scanf("%d %d %d", &a, &b, &c);
        double area, s;
        s = (a+b+c) / 2.0;
        area = sqrt(s*(s-a)*(s-b)*(s-c));
        printf("Area = %.3lf\n", area);
    }
    return 0;
}
