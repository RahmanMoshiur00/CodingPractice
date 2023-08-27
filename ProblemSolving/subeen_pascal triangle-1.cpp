#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    scanf("%d", &t);
    for(int l=1; l<=t; l++){
        int n;
        scanf("%d", &n);
        vector<int> arr[n+1];
        arr[0].push_back(1);
        for(int i=1; i<n+1; i++){
            arr[i].push_back(1);
            for(int j=0; j<i-1; j++){
                int sum = 0;
                sum = arr[i-1][j] + arr[i-1][j+1];
                arr[i].push_back(sum);
            }
            arr[i].push_back(1);
        }

        for(int i=0; i<n+1; i++){
            for(int j=0; j<arr[i].size(); j++){
                printf("%d", arr[i][j]);
                if(j==arr[i].size()-1) printf("\n");
                else printf(" ");
            }
        }
        printf("\n");
    }
    return 0;
}
