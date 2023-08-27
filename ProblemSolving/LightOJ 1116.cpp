#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    scanf("%d", &t);
    for(int l=1; l<=t; l++){
        long long int num;
        scanf("%lld", &num);
        long long odd, even;
        if(num%2==1){
            printf("Case %d: Impossible\n", l);
            continue;
        }
        else{
            odd = num / 2;
            even = 2;
            while(odd%2==0){
                odd /= 2;
                even *= 2;
            }
            printf("Case %d: %lld %lld\n", l, odd, even);
        }
    }
    return 0;
}
