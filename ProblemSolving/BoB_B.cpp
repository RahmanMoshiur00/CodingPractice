#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin>>t;
    for(int Case = 1; Case<=t; Case++){
        double r, counter = 0.0;
        cin>>r;
        while(r > 0.0001){
            counter += r;
            r = r / sqrt(2.00);
        }
        printf("%.1lf\n", counter);
    }
    return 0;
}
