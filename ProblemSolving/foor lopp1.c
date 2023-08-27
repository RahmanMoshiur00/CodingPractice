#include <stdio.h>

int main()
{
    int m, sum = 0;

    for(scanf("%d", &m); m <= 5; m = m + 1){
        printf("%d\n", m);
        sum = sum + m;}

        printf("Sum is %d", sum);

        return 0;
}
