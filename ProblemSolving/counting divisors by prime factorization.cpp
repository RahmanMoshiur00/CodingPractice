#include<bits/stdc++.h>
using namespace std;
int divisor_counter(int n){
    vector<int> divisors;
    for(int i=2; i*i<=n; i++){
        int counter = 0;
        while(n%i==0){
            n /= i;
            counter++;
        }
        if(counter>0) divisors.push_back(counter);
    }
    if(n>1) divisors.push_back(1);
    int nDivisor = 1;
    for(int i=0; i<divisors.size(); i++) nDivisor *= divisors[i] + 1;
    return nDivisor;
}


int main()
{
    int n;
    while(scanf("%d", &n), n) printf("Number of Divisors = %d\n", divisor_counter(n));
    return 0;
}
