#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    scanf("%d", &t);
    for(int l=1; l<=t; l++){
        int n, que;
        scanf("%d %d", &n, &que);
        vector<int> v(n);
        for(int i=0; i<n; i++) scanf("%d", &v[i]);
        sort(v.begin(), v.end());
        printf("Case %d:\n", l);
        while(que--){
            int x, y, t, ans1, ans2;
            scanf("%d %d %d", &x, &y, &t);
            if(((x-t)<v[0] || (x-t)>v[n-1]) && ((y-t)<v[0] || (y-t)>v[n-1])) printf("0\n");
            else{
                vector<int>::iterator it;
                int input = x-t;
                if (input < v.front() || input > v.back()) {
                    ans1 = 0;
                }

                else {
                    it = upper_bound(v.begin(), v.end(), input);
                    ans1 = it - v.begin();
                }

                input = y-t;
                if (input < v.front() || input > v.back()) {
                    ans2 = 0;
                }

                else {
                    it = upper_bound(v.begin(), v.end(), input);
                    ans2 = it - v.begin();
                }

                printf("%d\n", ans2-ans1);
            }
        }
    }
    return 0;
}
