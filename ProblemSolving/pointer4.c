#include<stdio.h>
void print()
{
    printf("puchki\n");
}
int* add(int* x, int* y)
{
    int* z = (int*)malloc(sizeof(int));
    *z = *x + *y;
    return z;
}
int main()
{
    int a = 2, b = 3;
    int* c = add(&a,&b);
    print();
    printf("sum=%d\n", *c);

}
