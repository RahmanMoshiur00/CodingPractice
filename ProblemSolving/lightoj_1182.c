#include<stdio.h>
int main()
{
    int t, l;
    scanf("%d", &t);
    for(l=1; l<=t; l++){
        int n, ans=0, i;
        scanf("%d", &n);
        for(i=1; n!=0;i++){
            ans += n%2;
            n = n/2;
        }
        if(ans%2==0) printf("Case %d: even\n", l);
        else printf("Case %d: odd\n", l);
    }
}
