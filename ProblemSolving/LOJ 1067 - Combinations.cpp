#include<bits/stdc++.h>
using namespace std;
typedef long long intt;
#define MOD     1000003
#define MX      1000005

intt f[MX];

void factorial_generate(){
    f[0] = f[1] = 1;
    for(int i=2; i<MX; i++) f[i] = (f[i-1] * i) % MOD;
}

intt BigMod(intt b, intt p, intt M){
    if(p==0) return 1%M;
    if(p&1) return (b*BigMod(b, p-1, M))%M;
    else{
        intt temp = BigMod(b, p/2, M);
        return (temp*temp)%M;
    }
}

intt ModInverse(intt b, intt M){
    return BigMod(b, M-2, M);
}

int main(){
    factorial_generate();
    intt n, k, tc;
    scanf("%lld", &tc);
    for(intt t=1; t<=tc; t++){
        scanf("%lld %lld", &n, &k);
        intt res = (f[n] * ((ModInverse(f[k], MOD) * ModInverse(f[n-k], MOD))%MOD)) % MOD;
        printf("Case %lld: %lld\n", t, res);
    }
    return 0;
}
