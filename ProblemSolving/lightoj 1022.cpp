#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    scanf("%d", &t);
    for(int l=1; l<=t; l++){
        double r;
        scanf("%lf", &r);
        double pi = 2.0 * acos(0.0);
        printf("Case %d: %.2lf\n", l, (4*r*r)-(pi*r*r));
    }
    return 0;
}
