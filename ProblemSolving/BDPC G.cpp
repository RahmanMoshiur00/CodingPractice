#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    scanf("%d ", &n);
    vector <long long> arr(n);
    for(int i=0; i<n; i++) scanf("%lld", &arr[i]);
    int ques;
    scanf("%d ", &ques);
    vector <long long>::iterator it;

    for(int i=0; i<ques; i++){
        long long q;
        scanf("%lld", &q);
        if((q>arr[n-1]) || (q<arr[0])) printf("-1\n");
        else{
            it = upper_bound(arr.begin(), arr.end(), q);
            cout<<it - arr.begin()<<endl;
        }
    }
    return 0;
}
