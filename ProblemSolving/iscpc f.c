#include <stdio.h>

int main()
{
    int n, mosq = 0;
    while(scanf("%d", &n)!=EOF){
        mosq += n;
    }

    printf("%d\n", mosq);

    return 0;
}
