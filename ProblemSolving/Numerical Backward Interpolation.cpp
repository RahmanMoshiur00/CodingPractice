#include<bits/stdc++.h>
using namespace std;

double counter(double p, int n)
{
    if(n == 0) return 1;
    double up = 1;
    int down = 1;
    for(int i=0; i<n; i++){
        up *= p + i;
        down *= i + 1;
    }
    double res = up / down;
    return res;
}

int main()
{
    int n;
    cin>>n;

    double x[n], y[n], d[n][n];

    for(int i=0; i<n; i++){
        cin>>x[i]>>y[i];
    }

    for(int j=0; j<n; j++){
        d[0][j] = y[j];
    }
    for(int i=1; i<n; i++){
        for(int j=0; j<n-i; j++){
            d[i][j] = d[i-1][j+1] - d[i-1][j];
        }
    }

    int query;
    cin>>query;

    double xx, yy;
    while(query--){
        cin>>xx;
        double h = x[1] - x[0];
        double p = (xx - x[n-1]) / h;
        yy = 0;
        for(int i=0; i<n; i++){
            yy += d[i][n-i-1]*counter(p, i);
        }
        cout<<fixed<<setprecision(4)<<"x: "<<xx<<"  y: "<<yy<<endl;
    }

    return 0;
}


/*
5
0.10 0.1003
0.15 0.1511
0.20 0.2027
0.25 0.2553
0.30 0.3093
4
0.12
0.26
0.4
0.5
*/

/*
7
100 10.63
150 13.03
200 15.04
250 16.81
300 18.42
350 19.90
400 21.27
1
218
*/

