#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    scanf("%d", &t);
    for(int l=1; l<=t; l++){
        int n;
        scanf("%d", &n);
        int ans = 0;
        while(n!=0){
            ans += n%2;
            n /= 2;
        }
        if(ans%2==0) printf("Case %d: even\n", l);
        else printf("Case %d: odd\n", l);
    }
    return 0;
}
