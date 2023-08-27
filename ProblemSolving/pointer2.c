#include<stdio.h>
void sumof(int* a, int s)
{
    int sum =  0, i;
    for(i=0; i < s; i++) a[i] = 2 * a[i];
    //return sum;
    //printf("sum = %d\n", sum);
}
int main()
{
    int x[] = {1,2,3,4,5,6}, i;
    int size = sizeof(x)/sizeof(x[0]);
    sumof(x,size);
    for(i=0; i< size; i++) printf("%d ", x[i]);

}
