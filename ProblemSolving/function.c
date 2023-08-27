#include<stdio.h>

double pi = 3.14;

my_fnc()
{

    double pi = 3.1416;
}

int main()
{

    printf("%lf\n", pi);

    my_fnc();
    printf("%lf", pi);
}

