#include<stdio.h>
int i = 0, sum =0;
int sumofnumbers(int n)
{
    sum += i;
    if(i == n) return sum;
    else{
       i++;
    sumofnumbers(n);
    }

}
int main()
{
    int n, s;
    printf("Enter number of (N):");
    scanf("%d", &n);
    s = sumofnumbers(n);
    printf("sum of numbers(1 to N):%d\n", s);
}
