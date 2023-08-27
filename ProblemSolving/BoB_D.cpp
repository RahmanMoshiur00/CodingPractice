#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin>>t;
    double fib[37];
    fib[0] = 0.0;
    fib[1] = 1.0;
    fib[2] = 1.0;
    for(int i=3; i<=37; i++) fib[i] = fib[i-1] + fib[i-2];
    while(t--){
        double result = 0.0;
        int n;
        cin>>n;
        for(int i=1; i<=n; i++){
            result += (fib[i] * fib[i]) - ((3.141593 * fib[i] * fib[i]) / 4.0);
        }
        printf("%.2lf\n", result);
    }
}
