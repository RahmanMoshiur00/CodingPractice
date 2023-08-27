#include <bits/stdc++.h>
using namespace std;
#define pb push_back

void find_div(vector<int>& d, int n, int l){
    for(int i=1; i<=sqrt(n*1.0000001); i++){
        if(n%i==0){
            if(i*i==n && i>l) d.pb(i);
            else{
                if(i>l) d.pb(i);
                if(n/i>l) d.pb(n/i);
            }
        }
    }
}

int main()
{
    int tc, p, l, sz; scanf("%d", &tc);
    for(int t=1; t<=tc; t++){
        vector<int> div;
        scanf("%d %d", &p, &l);
        find_div(div, p-l, l);
        sort(div.begin(), div.end());
        sz = div.size();
        printf("Case %d:", t);
        if(sz==0){ printf(" impossible\n"); continue; }
        for(int i=0; i<sz; i++){
            printf(" %d", div[i]);
        }
        printf("\n");
    }
    return 0;
}
