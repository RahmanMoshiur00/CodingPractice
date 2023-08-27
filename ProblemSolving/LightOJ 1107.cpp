#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    scanf("%d ", &t);
    for(int l=1; l<=t; l++){
        int lx, ly, hx, hy;
        scanf("%d %d %d %d", &lx, &ly, &hx, &hy);
        int q;
        scanf("%d", &q);
        printf("Case %d:\n", l);
        for(int i=0; i<q; i++){
            int x, y;
            scanf("%d %d", &x, &y);
            if((x>lx && x<hx) && (y>ly && y<hy)) printf("Yes\n");
            else printf("No\n");
        }
    }
    return 0;
}
