#include<bits/stdc++.h>
using namespace std;

int totient(int n){
    int result = n;
    for(int i=2; i*i<=n; i++){
        if(n%i==0){
            while(n%i==0) n /= i;
            result = result - (result/i);
        }
    }
    if(n>1) result = result - (result/n);
    return result;
}

int main()
{
    int n;
    while(scanf("%d", &n)==1) printf("Totient Function of %d = %d\n", n, totient(n));
    return 0;
}
