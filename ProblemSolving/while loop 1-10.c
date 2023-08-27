#include <stdio.h>

int main()
{
    int m;
    scanf("%d", &m);

    while(m <= 100){
        if(m % 2 == 0){
            printf("%d\n", m);
        }

        m = m + 1;
    }
    return 0;
}
