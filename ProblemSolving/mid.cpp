#include<bits/stdc++.h>
using namespace std;


int main()
{
    cout<<"Enter number of input: ";
    int n;
    cin>>n;

    double x[n] , y[n];
    for(int i=0; i<n; i++){
        cin>>x[i]>>y[i];
    }


    double Y0[n];
    vector<double> vy(y, y+n), dy;
    for(int j=0; j<n; j++){
        for(int i=0; i+1<vy.size(); i++){
            dy.push_back(vy[i+1] - vy[i]);
        }
        vy = dy;
        dy.clear();

        Y0[j] = vy[0];
    }

    double X;
    cout<<"Enter X: ";
    cin>>X;

    double p = (X-x[0]) / (x[1]-x[0]);
    double res = y[0], up, fact;

    for(int i=0; i<n; i++){
        up = 1.0, fact = 1.0;
        for(int j=0; j<=i; j++){
            fact *= j + 1.0;
            up *= p - j;
        }

        res += (up / fact) * Y0[i];
    }

    cout<<"Solution = "<<res<<endl;

    return 0;
}
