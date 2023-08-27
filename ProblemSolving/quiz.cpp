#include<bits/stdc++.h>
using namespace std;

#define EPS 1e-4
#define ERR 1e-9

double f(double x){
    return (x*x*x*x*x) - (5*x) - 1;
}

void bisection(double a, double b){
    if(f(a)*f(b)>ERR){
        cout<<"Range value is invalid to perform bisection method!"<<endl;
        return;
    }

    double c = a;
    while(b-a > EPS){
        c = (a+b)/2;

        if(f(c) == ERR) break;
        else if(f(c)*f(a) < ERR) b = c;
        else a = c;
    }

    cout<<"Root = "<<c<<endl;
}

int main()
{
    double a = -100.00, b = 200.00;

    bisection(a, b);

    return 0;
}
