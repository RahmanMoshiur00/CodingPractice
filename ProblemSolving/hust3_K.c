#include<stdio.h>
int main()
{
    int n,k,s,b,tb,r;
    while(scanf("%d%d",&n,&k)==2){
        s=n;
        tb=0;
        while(s>=k){
            b=s/k;
            r=s%k;
            s=b+r;
            tb=tb+b;
        }
        printf("%d\n", n+tb);
    }
    return 0;
}
