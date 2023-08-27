#include<bits/stdc++.h>
using namespace std;

int C[100][100];

int Combination(int n, int r){
    if(n==r){
        C[n][r] = 1;
        return 1;
    }
    else if(r==1){
        C[n][r] = n;
        return n;
    }
    if(C[n][r] == 0) C[n][r] = Combination(n-1, r) + Combination(n-1, r-1);
    return C[n][r];
}

int main()
{
    cout<<"Enter n and r to find nCr: ";
    int n, r; cin>>n>>r;
    Combination(n, r);
    cout<<C[n][r]<<endl;
}
