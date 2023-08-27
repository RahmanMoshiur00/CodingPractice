#include<bits/stdc++.h>
using namespace std;
#define MX  10500000

double lg[MX];

void lg_generate(){
    lg[1] = 0.0;
    for(int i=2; i<MX; i++) lg[i] = lg[i-1] + log(i);
}

int factor_counter(int n, int p){
    int res = 0;
    while(n/p > 0){
        res += n/p;
        n /= p;
    }
    return res;
}

int zeros(int n, int b){
    int res = INT_MAX, cnt = 0;
    for(int i=2; i<=sqrt(b)+1; i++){
        if(b%i==0){
            cnt = 0;
            while(b%i==0){
                cnt++;
                b /= i;
            }
            res = min(res, factor_counter(n, i)/cnt);
        }
    }
    if(b>1) res = min(res, factor_counter(n, b));
    return res;
}

int main()
{
    lg_generate();
    int tc, n, b;
    while(scanf("%d %d", &n, &b) != EOF){
        printf("%d %d\n", zeros(n, b), (int)(1.000000001 + (lg[n]/log(b))));
    }
    return 0;
}

