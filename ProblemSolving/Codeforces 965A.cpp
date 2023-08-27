#include<bits/stdc++.h>
using namespace std;

int main()
{
    int k, n, s, p, a, b, c;
    cin>>k>>n>>s>>p;
    if(n%s==0) a = n/s;
    else a = 1 + (n / s);
    b = k*a;
    if(b%p==0) c = b/p;
    else c = 1 + (b/p);

    cout<<c<<endl;

    return 0;
}
