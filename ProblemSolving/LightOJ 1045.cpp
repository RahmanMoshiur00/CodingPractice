#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    scanf("%d", &t);
    vector<double> ans(1000001);
    for(int i=1; i<=1000001; i++){ //don't start loop from 0, because log(0) is undefined!
        ans[i] = ans[i-1] + log(i); //like, ans[1] = (ans[0]=0) + log(1); then, ans[2] = ans[1] + log(2) which means ans[2] = 0+log(1)+log(2); then, ans[3] = 0+log(1)+log(2)+log(3) and so on...
    }
    for(int l=1; l<=t; l++){
        int num, base;
        scanf("%d %d", &num, &base);
        double result = ans[num] / log(base);
        printf("Case %d: %d\n", l, 1+(int)result);
    }
    return 0;
}
