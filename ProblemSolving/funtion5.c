#include<stdio.h>

double pi = 3.14;

void my()
{
   pi = 3.1416;
}

int main()
         {
             printf("%lf\n", pi);
             my();
             printf("%lf", pi);
         }
