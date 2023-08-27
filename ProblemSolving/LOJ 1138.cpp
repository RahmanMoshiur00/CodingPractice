#include<bits/stdc++.h>
using namespace std;

int fives(int n){
    int counter = 0;
    while(n/5>0){
        counter += n/5;
        n /= 5;
    }
    return counter;
}

int main()
{
    int tc, n, res, lo, hi, mid;
    scanf("%d", &tc);

    for(int t=1; t<=tc; t++){
        scanf("%d", &n);

        res = 0; lo = 1; hi = 1000000000;
        while(lo<=hi){
            mid = (lo+hi)/2;
            if(fives(mid)==n){
                res = mid;
                hi = mid - 1;
            }
            else if(fives(mid)>n) hi = mid - 1;
            else lo = mid + 1;
        }
        if(res==0) printf("Case %d: impossible\n", t);
        else printf("Case %d: %d\n", t, res);
    }
    return 0;
}
