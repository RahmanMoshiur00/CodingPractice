#include<stdio.h>
int main()
{
    int j, k, i, n;
    scanf("%d", &k);
    for(j=0; j<k; j++){
        int count = 1;
        printf("Enter the number:");
        scanf("%d", &n);

        for(i=0; i <= n-1; i++){
            count = count * (n - i);
        }
        printf("factoril of %d is %d\n\n", n, count);
    }
}
