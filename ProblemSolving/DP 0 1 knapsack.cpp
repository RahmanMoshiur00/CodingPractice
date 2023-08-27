#include<bits/stdc++.h>
using namespace std;

int knapsack(int weight[], int benifit[], int n, int knapCapacity){
    int dp[n+1][knapCapacity+1];

    for(int i=0; i<=n; i++){
        for(int j=0; j<=knapCapacity; j++){
            if(i==0 || j==0) dp[i][j] = 0;
            else if(weight[i-1]<=j){ //if weight is less then or equal to capacity we can either take that element or not
                dp[i][j] = max(dp[i-1][j], benifit[i-1]+dp[i-1][j-weight[i-1]]);// storing the maximum between benifit of not taking the element and benifit by taking the element
            }
            else dp[i][j] = dp[i-1][j];
        }
    }
    return dp[n][knapCapacity];
}


int main()
{
    cout<<"Enter how many items you have: ";
    int n; cin>>n;

    int weight[n], benifit[n];

    for(int i=0; i<n; i++) cin>>weight[i]>>benifit[i];

    cout<<"Enter the capacity of knapsack: ";
    int knapCapacity; cin>>knapCapacity;

    cout<<knapsack(weight, benifit, n, knapCapacity)<<endl;

    return 0;
}
