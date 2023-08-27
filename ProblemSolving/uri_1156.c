#include<stdio.h>
int main()
{
    int i, j;
    double sum = 1.0;
    for(i=3, j=2; i<=39; i+=2, j*=2){
        sum += (double)i / (double)j;
    }
    printf("%.2lf\n", sum);
}
