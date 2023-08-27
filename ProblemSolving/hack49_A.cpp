#include<bits/stdc++.h>
using namespace std;

int main()
{
    long long n, ans = 1;
    scanf("%lld", &n);
    for(int i=0; i<n; i++){
        long long num;
        scanf("%lld", &num);
        ans *= num;
    }

    long long result = (ans*4) / 1024;
    printf("%lld\n", result);

    return 0;
}
