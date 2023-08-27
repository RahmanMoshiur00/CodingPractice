#include<bits/stdc++.h>
using namespace std;

int fib[10000];

int Fibo(int n){
    if(n==1){
        fib[n] = 0;
        return 0;
    }
    else if(n==2){
        fib[n] = 1;
        return 1;
    }

    if(fib[n] == -1) fib[n] = Fibo(n-1) + Fibo(n-2);

    return fib[n];
}

int main()
{
    for(int i=0; i<10000; i++) fib[i] = -1;
    cout<<"Enter n to find the nth fibonacci number: ";
    int n; cin>>n;
    cout<<Fibo(n)<<endl;
}
