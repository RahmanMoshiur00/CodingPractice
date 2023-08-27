#include<stdio.h>
int main()
{
    int n=1, i;
    for(i=n; i<10; i++){

        if(i==5) continue;
        printf("%d ", i);
    }
    printf("%d", i+1);
}
