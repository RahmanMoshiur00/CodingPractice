#include<bits/stdc++.h>
using namespace std;
#define EPS    1e-4

double f(double x) // x^5 - 5x - 1
{
    return ((x*x*x*x*x) - (5*x) - 1);
}

double f1(double x) // 5x^4 - 5
{
    return (5*x*x*x*x) - 5;
}

void newtonRaphson(double Xn)
{
    double Xn1 = Xn - (f(Xn)/f1(Xn));

    while(abs(Xn1 - Xn) >= EPS)
    {
        Xn = Xn1;
        Xn1 = Xn - (f(Xn)/f1(Xn));
    }
    cout<<fixed<<setprecision(3)<< "The value of root is : " <<Xn1<<endl;;
}


int main()
{
    double a = 2;
    newtonRaphson(a);
    return 0;
}


