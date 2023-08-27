#include<stdio.h>
void print(){
    printf("puchki\n");
}
int add(int* n, int* m)
{
    return (*n + *m);
}
main()
{
    int n=3, m=7;
    printf("%d\n", add(&m, &n));
}
