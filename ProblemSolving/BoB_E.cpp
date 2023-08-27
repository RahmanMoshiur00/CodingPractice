#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n, m;
    scanf("%d %d", &n, &m);

    int arr[n+1][n+1] = {0};
    int a, b, c;
    long long counter = 0;

    for(int i=1; i<=m; i++){
        scanf("%d %d %d", &a, &b, &c);
        if(arr[a][b] == 0){
            arr[a][b] = c;
            arr[b][a] = c;
        }
        else if(c < arr[a][b]){
                arr[a][b] = c;
                arr[b][a] = c;
        }
    }

    for(int i=1; i<=n; i++){
        for(int j=i+1; j<=n; j++) counter += arr[i][j];
    }
    printf("%lld\n", 2*counter);

    return 0;
}
