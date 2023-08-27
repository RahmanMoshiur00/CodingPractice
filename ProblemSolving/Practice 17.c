/*22*/
#include<stdio.h>
int pow = 1, i = 0;
int power(int a, int b)
{
    pow *= a;
    i++;
    if(i==b) return pow;
    power(a, b);
}
int main()
{
    int a, b;
    printf("Enter a number:");
    scanf("%d", &a);
    printf("Enter the power of the number:");
    scanf("%d", &b);
    int pow = power(a, b);
    printf("%d to the power %d = %d", a, b, pow);

}
