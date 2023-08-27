#include<bits/stdc++.h>
using namespace std;
#define MAX 10000

int dp[MAX][MAX];
vector<char> path;

int LCS(string& str1, string& str2){ // we have to find subsequence of str2 in str1

    int len1 = str1.length();
    int len2 = str2.length();

    for(int i=0; i<=len1; i++){
        for(int j=0; j<=len2; j++){
            if(i==0 || j==0) dp[i][j] = 0;
            else if(str1[i-1] == str2[j-1]){ //because str1, str2 starts from index 0; but we're calculating from 1
                dp[i][j] = dp[i-1][j-1] + 1;
            }
            else dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
        }
    }

    return dp[len1][len2];
}

void printPath(string& str1, string& str2, int len1, int len2){
    if(len1==0 || len2==0) return;
    else if(str1[len1-1] == str2[len2-1]){
        path.push_back(str1[len1-1]);
        printPath(str1, str2, len1-1, len2-1);
    }
    else if(dp[len1-1][len2] >= dp[len1][len2-1]) printPath(str1, str2, len1-1, len2);
    else printPath(str1, str2, len1, len2-1);
}

int main()
{
    cout<<"Enter how many tests you want to have on LCS: ";
    int t; cin>>t;

    while(t--){
        cout<<"\nEnter two strings to find LCS by newline:\n";
        string str1, str2;
        cin>>str1>>str2;

        int L1 = str1.length();
        int L2 = str2.length();

        cout<<LCS(str1, str2)<<endl;
        cout<<"Printing path: ";
        printPath(str1, str2, L1, L2);

        cout<<"Printing path: ";
        for(int i=path.size()-1; i>=0; i--) cout<<path[i]<<" ";
        cout<<endl;
        path.clear();
    }

    return 0;
}
