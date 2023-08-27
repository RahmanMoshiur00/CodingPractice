#include<stdio.h>

int main()
{
    unsigned int n, x, i, j;
    while(scanf("%u %u", &n, &x) == 2){
        int count = 0;
        for(i=1; i<=n; i++){
            for(j=1; j<=n; j++){
                if(i*j == x) count++;
            }
        }
        printf("%d\n", count);
    }

    return 0;
}
