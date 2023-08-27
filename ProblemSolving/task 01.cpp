#include <bits/stdc++.h>
using namespace std;

#define ERROR 1e-4

double f(double x)
{
    double y = (x*x*x*x*x) - (5*x) - 1;
    return y;
}

double f1(double x)
{
    double y = (5*x*x*x*x) - 5;
    return y;
}

void NewtonRaphson(double Xn)
{
    double Yn = Xn - (f(Xn) / f1(Xn));
    while(abs(Yn - Xn) > ERROR){
        Xn = Yn;
        Yn = Xn - (f(Xn) / f1(Xn));
    }
    cout<<fixed<<setprecision(5)<<"Root = "<<Yn<<endl;
}

int main()
{
    NewtonRaphson(3.0);

    return 0;
}
