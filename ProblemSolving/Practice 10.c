#include<stdio.h>
int i = 0,count = 1;
int fact(int n)
{
    count *= (n - i);
    if(i == n-2) return count;
    i++;
    fact(n);

}
int main()
{
    int n;
    scanf("%d", &n);
    int f = fact(n);
    printf("%d! = %d", n, f);
}
