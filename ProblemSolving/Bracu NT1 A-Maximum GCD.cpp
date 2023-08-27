#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t, n, sz, ans;
    scanf("%d ", &t);
    string str;
    vector<int> num;

    while(t--)
    {
        getline(cin, str);
        istringstream ss(str);
        while(ss>>n){
            num.push_back(n);
        }
        ans = INT_MIN;
        sz = num.size();
        for(int i=0; i<sz; i++){
            for(int j=i+1; j<sz; j++){
                ans = max(ans, __gcd(num[i], num[j]));
            }
        }
        cout<<ans<<endl;
        num.clear();
    }

    return 0;
}
