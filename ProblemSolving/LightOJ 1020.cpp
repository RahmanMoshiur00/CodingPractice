#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t; scanf("%d", &t);
    long long n;
    char str[10];

    for(int tc=1; tc<=t; tc++){
        scanf("%lld %s", &n, str);
        if(str[0] == 'A'){
            if(n&1) printf("Case %d: Bob\n", tc);
            else printf("Case %d: Alice\n", tc);
        }
        else{
            if(n&1) printf("Case %d: Alice\n", tc);
            else printf("Case %d: Bob\n", tc);
        }
    }

    return 0;
}
