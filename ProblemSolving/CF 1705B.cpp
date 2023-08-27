#include <bits/stdc++.h>
using namespace std;

void solve(int tc)
{
   int n;
   cin >> n;

   int arr[n];
   for(int i=0; i<n; i++) cin >> arr[i];

   int idx = -1;
   for(int i=0; i<n-1; i++){
        if(arr[i] != 0){
            idx = i;
            break;
        }


//        if(arr[i]==0){
//            num_of_zero = 0;
//            for(j=i; j<n-1; j++){
//                if(arr[j] != 0) break;
//                num_of_zero++;
//            }
//            i = j-1;
//            if(sum_before_zero > 0){
//                ans += num_of_zero + sum_before_zero;
//                sum_before_zero = 0;
//            }
//        }
//        else{
//            sum_before_zero += arr[i];
//        }
   }

   int zero = 0, sum = 0, ans = 0;
   if(idx != -1){
    for(int i=idx; i<n-1; i++){
            if(arr[i]==0) zero++;
            sum += arr[i];
       }
   }

   ans = sum + zero;

   cout << ans << endl;
}

int main()
{
    int tc;
    cin >> tc;

    for(int i=1; i<=tc; i++) solve(i);

    return 0;
}
