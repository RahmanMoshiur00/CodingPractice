#include<bits/stdc++.h>
using namespace std;
#define EPSILON 0.0001
#define ERR     0

double f(double x)
{
    return (x*x*x) - (x*x) + 2;
}

void bisection(double a, double b)
{
    if( !(f(a) * f(b) < 0) )
    {
        cout << "You have not assumed right a and b\n";
        return;
    }

    double c = a;
    while(a<=b)
    {
        c = (a+b)/2;
        if(f(c) == 0) break;
        else if(f(a)*f(c) < 0) b = c;
        else a = c;
    }
    cout<<fixed<<setprecision(3)<< "Root = " << c<<endl;;
}


int main()
{
    double a = -2, b = 3;
    bisection(a, b);
    return 0;
}
