#include<bits/stdc++.h>
using namespace std;
#define intt   long long
#define MX     10000000

bool checker[MX];
vector< pair<int, int> > goldbach_pair;

void sieve(int mx){
    checker[0] = checker[1] = true;
    for(int i=4; i<=mx; i+=2) checker[i] = true;
    int sq = sqrt(mx) + 2;
    for(int i=3; i<=mx; i+=2){
        if(!checker[i]){
            if(i<=sq){
                for(int j=i*i; j<=mx; j+=i*2) checker[j] = true;
            }
        }
    }
}


int goldbach_solution(int n){
    int ans = 0;
    for(int i=2; i<=n/2; i++){
        if(checker[i]==false && checker[n-i]==false){
            goldbach_pair.push_back({i, n-i});
            ans++;
        }
    }
    return ans;
}

int main()
{
    sieve(1000000); //10^7

    /*
    Input:
    3
    32768
    10
    29
    Output:

    */

    int q, n;
    cin>>q;
    while(q--){
        cin>>n;
        cout<<goldbach_solution(n)<<endl;
        int sz = goldbach_pair.size();
        for(int i=0; i<sz; i++){
            cout<<goldbach_pair[i].first<<" "<<goldbach_pair[i].second<<endl;
        }
        goldbach_pair.clear();
    }
}
