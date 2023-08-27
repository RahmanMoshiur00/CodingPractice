#include <stdio.h>

int main()
{
    int m;

    for(scanf("%d", &m); m <= 30; m = m + 1){
        printf("%d\n", m);
        continue;

        if(m % 2 == 0){
            printf("%d\n", m);
        }
    }
    return 0;
}

