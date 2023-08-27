#include <bits/stdc++.h>
using namespace std;

int main()
{
    vector<long long> v;
    long long n, k;
    scanf("%lld %lld", &n, &k);
    int sq = sqrt(n) + 10;
    long long mark[sq]={0}, i, j=0, Count=0;
    for(i=1; i<=sqrt(n); i++)
    {
        if (n%i==0){
            if (n/i == i){
                v.push_back(n/i);
                Count++;
            }
            else{
                mark[j++] = i;
                v.push_back(n/i);
                Count+=2;
            }
        }
        if(j==k) break;
    }

    if(mark[k-1]!=0) printf("%lld\n", mark[k-1]);
    else if(k<=Count) {
        printf("%lld\n", v[v.size() - (k-j)]);
    }
    else printf("-1\n");

    return 0;
}

