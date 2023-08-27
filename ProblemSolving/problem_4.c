#include<stdio.h>
main()
{
    int j, n;
    scanf("%d", &j);
    for(n=0; n<j; n++){
        int i, N;
        scanf("%d", &N);
        printf("Case %d: ", n+1);
        for(i=1; i<=N; i++){
            if(N % i == 0) printf("%d ", i);
        }
        printf("\n");
    }
}
