#include<stdio.h>

int main()
{
    int s, n, i;
    for(s=1; s<=3; s++){
    scanf("%d", &n);

    for(i = 1; i <= 10; i++){
        printf("%d X %d = %d\n", n, i, n*i);
    }

    }
}
