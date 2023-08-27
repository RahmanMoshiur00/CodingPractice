#include<stdio.h>

int max, m = 1;
int findbiggest(int a[])
{
    if(max < a[m]){
        max = a[m];
        m++;
        return findbiggest(a);
    }
    else{
        return max;
    }
}
int main()
{
    int num[10] = {3, 5, 9, 12, 15, 45, 3};
    max = num[0];
    int n = findbiggest(num);
    printf("biggest number is %d\n", n);
}
