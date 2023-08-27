#include<stdio.h>
int fibo(int n)
{
    if(n==0) return 0;
    else if(n==1) return 1;
    return(fibo(n-1) + fibo(n-2));

}
int main()
{
    int n, f;
    printf("Enter the nth number of fibonnacci series:");
    scanf("%d", &n);
    f = fibo(n);
    printf("the %dth number of fibonnacci series is %d", n, f);
    return 0;
}
