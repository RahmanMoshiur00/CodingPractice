#include<stdio.h>
#include<time.h>
int fib(int n)
{
    if (n <= 1)
    return n;
    return fib(n-1) + fib(n-2);
}

int main()
{
    clock_t start, stop;
    start = clock();

    int n = 40;
    //scanf("%d", &n);

    double time_spent;

    printf("%d\n", fib(n));

    stop = clock();

    time_spent = (double)(stop - start) / CLOCKS_PER_SEC;

    printf("Time Taken %lf\n", time_spent);

    return 0;
}
