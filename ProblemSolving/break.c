#include <stdio.h>

int main()
{
    int m;

    for(scanf("%d", &m); m <= 30; m = m + 1){
            printf("%d\n", m);
            if (m >= 25){
                break;
            }
    }
    return 0;
}

