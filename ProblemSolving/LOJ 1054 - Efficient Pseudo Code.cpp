#include<bits/stdc++.h>
using namespace std;
typedef long long intt;
#define pb   push_back
#define mp   make_pair
#define MX   100000000
#define MD   1000000007

intt BigMod(intt b, intt p, intt M){
    if(p==0) return 1%M;
    if(p&1) return (b*BigMod(b, p-1, M))%M;
    else{
        intt temp = BigMod(b, p/2, M);
        return (temp*temp)%M;
    }
}

intt InverseMod(intt n, intt M){
    return BigMod(n, M-2, M);
}

intt prime_factorization(intt n, intt m){
    intt counter = 0, tmp, ans = 1;
    for(intt i=2; i<=sqrt(n)+1; i++){
        counter = 0;
        if(n%i==0){
            n /= i;
            counter++;
            while(n%i==0){
                n /= i;
                counter++;
            }
            tmp = BigMod(i, (m*counter)+1, MD)-1;
            tmp = ((tmp%MD) * InverseMod(i-1, MD)) % MD;
            ans = (ans * tmp) % MD;
        }
    }
    if(n!=1){
            if(n%MD==0) return 1; //n is prime; SOD of a prime number p = p + 1; (p^x+1)%p = 1 for any positive number x
            tmp = BigMod(n, m+1, MD)-1;
            tmp = ((tmp%MD) * InverseMod(n-1, MD)) % MD;
            ans = (ans * tmp) % MD;
    }
    return ans;
}


int main()
{

    intt tc, m, n;
    scanf("%lld", &tc);
    for(intt t=1; t<=tc; t++){
        scanf("%lld %lld", &n, &m);
        printf("Case %lld: %lld\n", t, prime_factorization(n, m));
    }

    return 0;
}

