#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    scanf("%d", &t);
    for(int l=1; l<=t; l++){
        int n;
        scanf("%d", &n);
        int arr[100][100];
        arr[1][0] = 1;
        arr[2][0] = 1;
        arr[2][1] = 1;
        for(int i=3; i<n+1; i++){
            arr[i][0] = 1;
            for(int j=1; j<i; j++){
                arr[i][j] = arr[i-1][j] + arr[i-1][j-1];
            }
            arr[i][j] = 1;
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
}
