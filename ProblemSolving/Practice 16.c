/*21*/
#include<stdio.h>
int i = 0, prod = 0;
int product(int a, int b)
{
    int n, m;
    if(a == 0 || b == 0) return 0;
    if(a<b){
        n = a;
        m = b;
    }
    else{
        n = b;
        m = a;
    }
    prod += m;
    i++;
    if(i == n) return prod;
    product(a, b);
}
int main()
{
    int a, b;
    printf("Enter two numbers to find product:");
    scanf("%d%d", &a, &b);
    int p = product(a, b);
    printf("prduct is %d", p);
}
