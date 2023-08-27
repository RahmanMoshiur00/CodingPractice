#include <stdio.h>

int main()
{
    int m;
    scanf("%d", &m);

    while(m <= 20){
        printf("%d\n", m);
        m = m + 1;
        if(m % 2 == 0){
            printf("%d\n", m);
        }
    }
    return 0;
}

