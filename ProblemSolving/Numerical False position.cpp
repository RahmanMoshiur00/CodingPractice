#include<bits/stdc++.h>
using namespace std;
#define EPS    1e-4
#define ERR    1e-9

double f(double x)
{
    return (x*x*x) - (x*x) + 2;
}

void falsePosition(double a, double b)
{
    if(f(a) * f(b) >= 0)
    {
        cout << "You have not assumed right a and b\n";
        return;
    }

    double c = a;
    while(a<=b)
    {
        c = (a*f(b) - b*f(a)) / (f(b) - f(a));
        if(f(c) == 0) break;
        else if(f(a)*f(c) < 0) b = c;
        else a = c;
    }
    cout<<fixed<<setprecision(3)<< "Root = " <<c<<endl;;
}


int main()
{
    double a = -2, b = 3;
    falsePosition(a, b);
    return 0;
}

