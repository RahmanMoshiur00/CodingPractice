#include<stdio.h>
int sum = 0;
int SumOfDigits(int a)
{
    int b, c;
    b = a % 10;
    c = a / 10;
    sum += b;
    if(c == 0) return sum;
    a = c;
    SumOfDigits(a);
}
int main()
{
    int a;
    printf("Enter the number:");
    scanf("%d", &a);
    int s = SumOfDigits(a);
    printf("Sum of digits:%d\n", s);
}
