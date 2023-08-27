#include<bits/stdc++.h>
using namespace std;

int main()
{
    int zack, zill;
    while(scanf("%d %d", &zack, &zill), (zack!=0 && zill!=0)){
        int cnt=0;

        map<int, int> cd;

        for(int i=1; i<=(zack+zill); i++){
            int n;
            scanf("%d", &n);
            if(cd[n]!=0){
                cnt++;
            }
            cd[n]++;
        }
        printf("%d\n", cnt);
    }

    return 0;
}

