#include<bits/stdc++.h>
using namespace std;

#define intt long long
#define pb   push_back
int main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);

    string str;
    vector<intt> num;
    intt n, mn = LONG_LONG_MAX;

    while(getline(cin, str)){
        if(str[0]=='0') break;

        mn = LONG_LONG_MAX;
        bool all_positive = true;

        stringstream ss(str);
        while(ss>>n) if(n!=0) num.pb(n);

        sort(num.begin(), num.end());

        intt mx = 0, sz = num.size();
        for(intt i=1; i<sz; i++) mx = __gcd(mx, num[i]-num[0]);

        //cout<<"DBG: mx="<<mx<<endl;

        intt counter = 1, ans = 1, mod;
        for(intt i=mx; i>=1; i--){
            counter = 1;
            if(num[0]>=0) mod = num[0]%i;
            else if(num[0]<0 && num[0]%i!=0) mod = (num[0]%i)+i;
            else if(num[0]<0 && num[0]%i==0) mod = 0;
            for(intt j=1; j<sz; j++) if(((num[j]>=0) && (num[j]%i==mod)) || ((num[j]<0) && ((num[j]%i==mod) || ((num[j]%i)+i)==mod))) counter++;
            if(counter==sz){
                ans = i;
                break;
            }
        }

        cout<<ans<<endl;
        num.clear();
    }

    return 0;
}
