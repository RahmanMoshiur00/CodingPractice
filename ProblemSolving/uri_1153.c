#include<stdio.h>
main()
{
    int n, fact=1, i;
    scanf("%d", &n);
    for(i=n; i>1; i--){
        fact *= i;
    }
    printf("%d\n", fact);
}
