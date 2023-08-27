#include<bits/stdc++.h>
using namespace std;



/*this following iterative solve has O(NW) time complexity;
here, N = number of items, W=max capacity of knapsack*/
int knapsack(int N, int W, vector<int>& weight, vector<int>& value){

    int dp[N+1][W+1];
    for(int i=0; i<=N; i++) for(int j=0; j<=W; j++) dp[i][j] = 0;

    for(int i=0; i<=N; i++){
        for(int j=0; j<=W; j++){
            if(i==0 || j==0) dp[i][j] = 0;
            else if(weight[i-1]<=j) dp[i][j] = max(value[i-1] + dp[i-1][j-weight[i-1]], dp[i-1][j]);
            else dp[i][j] = dp[i-1][j];
        }
    }

    return dp[N][W];
}

int main()
{
    cout<<"Enter how many items you have: ";
    int N, W;
    cin>>N;
    cout<<"Enter maximum capacity of your knapsack: ";
    cin>>W;


    vector<int> weight(N), value(N);
    cout<<"Enter weight and value of the items respectively:\n";
    for(int i=0; i<N; i++){
        cin>>weight[i]>>value[i];
    }

    int ans = knapsack(N, W, weight, value);
    cout<<"ANS = "<<ans<<endl;

    return 0;
}
