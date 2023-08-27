#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t, l;
    scanf("%d ", &t);

    for(l=1; l<=t; l++){
        long long u, a, s;
        scanf("%lld %lld %lld", &u, &a, &s);
        long double discriminant, t1 = 0.0, t2 = 0.0;

        long long temp = (u*u) + (2*a*s);
        discriminant = (long double)temp;

        long double ans = sqrt(discriminant);

        t1 = (long double)((u * -1.0) + ans) / (long double)a;
        t2 = (long double)((u * -1.0) - ans) / (long double)a;

        cout << fixed << setprecision(6);
        if(t1<0.0) cout<<"Case "<<l<<": "<<t2<<endl;
        else cout<<"Case "<<l<<": "<<t1<<endl;
    }

    return 0;
}
