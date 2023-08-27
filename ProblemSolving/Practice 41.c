/*75*/
#include<stdio.h>
int main()
{
    int n, i, j, a[30], sum = 1, temp;
    printf("Enter a number:");
    scanf("%d", &n);
    temp = n;

    for(i=2, j=0; i<=n; i++){
        if(n%i==0){
            a[j] = i;
            n = n / 2;
            j++;
            i = 1;
        }
    }

    for(i=0; i<j; i++) sum += a[i];

    if(sum == temp) printf("%d is a perfect number", temp);
    else printf("%d is not a perfect number", temp);
}
