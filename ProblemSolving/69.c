/*69*/
#include<stdio.h>
int sumOfElements(int *a, int size)
{
    int i, sum = 0;
    for(i=0; i<size; i++){
        sum += *(a+i);
    }
    return sum;
}
int main()
{
    int a[10] = {1,2,3};
    int size = (sizeof(a) / sizeof(int));
    int sum = sumOfElements(a, size);
    printf("SUM = %d", sum);
}
