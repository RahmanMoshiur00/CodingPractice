#include<bits/stdc++.h>
using namespace std;

int gcd(int a, int b){
    if(a==0) return b;
    else if(b==0) return a;
    return gcd(b, a%b);
}

int main()
{
    int n;
    cin>>n;

    int arr[n];
    for(int i=0; i<n; i++) scanf("%d", &arr[i]);

    vector<int> ans;

    for(int i=1; i<n; i++){
        int g = gcd(arr[i], arr[i-1]);
        if(ans[ans.size()-1] != g) ans.push_back(g);
    }

    if(ans.empty()) printf("-1\n");
    else{
        printf("%d\n%d", ans.size(), ans[0]);
        for(int i=1; i<ans.size(); i++){
            printf(" %d", ans[i]);
        }
        printf("\n");
    }

    return 0;
}
