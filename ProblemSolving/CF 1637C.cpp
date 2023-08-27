#include <bits/stdc++.h>
using namespace std;
#define int           long long
#define endl          '\n'
#define all(a)        a.begin(), a.end()
#define ZERO(a)       memset(a, 0, sizeof(a))
#define MINUS(a)      memset(a, 0xff, sizeof(a))
#define debug         if( 0 )

const int mxn = 100010;



void solve(int test_case)
{
    int n;
    cin >> n;

    int arr[n];
    for(int i=0; i<n; i++){
        cin >> arr[i];
    }

    vector<int> even;
    multiset<int> odd;
    for(int i=1; i<n-1; i++){
        if(arr[i]%2==1){
            odd.insert(arr[i]);
        }
        else{
            even.push_back(arr[i]);
        }
    }

    int ans = 0, omx, omn1, omn2;

    while(odd.size() >= 3){
        omx = *odd.rbegin();
        debug cout << "Check: " << omx << endl;
        if(omx == 1) break;
        odd.erase(odd.find(omx));

        omn1 = *odd.begin();
        odd.erase(odd.begin());

        omn2 = *odd.begin();
        odd.erase(odd.begin());

        omx -= 2;
        omn1++;
        omn2++;
        ans++;

        odd.insert(omx);
        even.push_back(omn1);
        even.push_back(omn2);
    }
    while(odd.size() >= 2){
        omx = *odd.rbegin();
        debug cout << "Check: " << omx << endl;
        if(omx == 1) break;
        odd.erase(odd.find(omx));

        omn1 = *odd.begin();
        odd.erase(odd.begin());

        omx--;
        omn1++;
        ans++;

        even.push_back(omx);
        even.push_back(omn1);
    }

    for(int i=0; i<even.size(); i++){
        while(odd.size() >= 2 && even[i]>=2){
            omn1 = *odd.begin();
            odd.erase(odd.begin());
            omn2 = *odd.begin();
            odd.erase(odd.begin());

            even[i] -= 2;
            omn1++;
            omn2++;
            ans++;
            even.push_back(omn1);
            even.push_back(omn2);
        }
        if(odd.size() == 1 && even[i]>=2){
            omn1 = *odd.begin();
            odd.erase(odd.begin());
            omn1++;
            even[i] -= 2;
            ans++;
            even.push_back(omn1);
        }
        ans += even[i] / 2;
    }

    if(!odd.empty()){
        cout << -1 << endl;
    }
    else{
        cout << ans << endl;
    }


}

int32_t main()
{
    //freopen("input.txt","r",stdin); //freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    //solve(1);
    int tc; cin >> tc; for(int t=1; t<=tc; t++) solve(t);

    return 0;
}

/*
3
6
1 2 5 7 9 10
4
1 4 7 10
6
1 3 3 3 3 6
*/
