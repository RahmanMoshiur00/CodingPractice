#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    scanf("%d", &t);

    for(int l=1; l<=t; l++){
        scanf(" ");
        int student, dust, ans = 0;
        scanf("%d", &student);
        for(int i=0; i<student; i++){
            scanf("%d", &dust);
            if(dust>0) ans += dust;
        }
        printf("Case %d: %d\n", l, ans);
    }
    return 0;
}
