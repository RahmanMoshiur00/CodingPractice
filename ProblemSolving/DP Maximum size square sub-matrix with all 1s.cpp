#include<bits/stdc++.h>
using namespace std;

int maxSquare(vector<string>& arr){
    int row = arr.size();
    int column = arr[0].size();
    int dp[row][column];
    int ans = 0;

    for(int i=0; i<row; i++){
        for(int j=0; j<column; j++){
            if(i==0 || j==0 || arr[i][j]=='0') dp[i][j] = arr[i][j] - '0'; //dp[][] will be the same of arr[][] at firt row and column, and when arr[][] is '0'
            else if(arr[i][j] == '1'){
                dp[i][j] = min(dp[i][j-1], min(dp[i-1][j-1], dp[i-1][j])) + 1;
                if(dp[i][j] > ans) ans = dp[i][j];
            }
        }
    }

    //printing the illustration table
    cout<<"Table:\n";
    for(int i=0; i<row; i++){
        for(int j=0; j<column; j++) cout<<dp[i][j];
        cout<<endl;
    }

    return ans;
}

int main()
{
    cout<<"Enter how many binary/bit strings(only contains 0 and 1) with same length: ";
    int n; cin>>n;
    vector<string> arr(n);
    for(int i=0; i<n; i++) cin>>arr[i];

    cout<<"Maximum size square sub-matrix with all 1s: "<<maxSquare(arr);

}
