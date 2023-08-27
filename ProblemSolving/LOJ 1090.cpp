#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

ll count_five(ll n){
    ll counter = 0;
    while(n/5>0){
        counter += n/5;
        n /= 5;
    }
    return counter;
}

ll count_two(ll n){
    ll counter = 0;
    while(n/2>0){
        counter += n/2;
        n /= 2;
    }
    return counter;
}

ll factor_two(ll n){
    ll counter = 0;
    while(n%2==0){
        counter++;
        n /= 2;
    }
    return counter;
}

ll factor_five(ll n){
    ll counter = 0;
    while(n%2==0) n /= 2;
    while(n%3==0) n /= 3;
    while(n%5==0){
        counter++;
        n /= 5;
    }
    return counter;
}

int main()
{
    int tc;
    ll n, r, p, q, a1, a2, a3, a4, b1, b2, b3, b4, ans;
    scanf("%d", &tc);
    for(int t=1; t<=tc; t++){
        scanf("%lld %lld %lld %lld", &n, &r, &p, &q);
        a1 = count_two(n);
        a2 = count_two(r);
        a3 = count_two(n-r);
        a4 = q * factor_two(p);
        b1 = count_five(n);
        b2 = count_five(r);
        b3 = count_five(n-r);
        b4 = q * factor_five(p);
        ans = min(a1-a2-a3+a4, b1-b2-b3+b4);
        printf("Case %d: %lld\n", t, ans);
    }
    return 0;
}
