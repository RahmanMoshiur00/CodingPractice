#include<stdio.h>
int main()
{
    int t, i, n, res;
    scanf("%d", &t);
    for(i=1; i<=t; i++){
        scanf("%d", &n);
        if(n>=6) res = 9;
        else{
            int fac=1;
            while(n) fac *= n--;
            res=0;
            while(fac != 0){
                res += fac%10;
                fac /= 10;
            }
        }
        printf("Case %d: %d\n", i, res);
    }
}
