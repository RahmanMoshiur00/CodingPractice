#include<stdio.h>
int main()
{
    int t, i;
    scanf("%d", &t);
    for(i=1; i<=t; i++){
        int n, j;
        scanf("%d", &n);
        int num[n];
        for(j=0; j<n; j++){
            scanf("%d", &num[j]);

        }
        if((num[1]-num[0]) == (num[2]-num[1])) printf("%d\n", num[n-1]+num[1]-num[0]);
        else if((num[1]/num[0]) == (num[2]/num[1])) printf("%d\n", num[n-1]*(num[1]/num[0]));
    }
}
