#include<bits/stdc++.h>
using namespace std;

int main()
{
    vector<int> fib[35];
    int f[40];
    f[0] = 0;
    f[1] = 1;
    for(int i=2; i<=36; i++) f[i] = f[i-1] + f[i-2];
    //for(int i=0; i<36; i++) printf("%d ", f[i]);
    for(int i=2; i<=36; i++){
        fib[i].push_back(f[i-1]);
        fib[i].push_back(f[i-2]);
    }
    cout<<fib[2][1];

}
