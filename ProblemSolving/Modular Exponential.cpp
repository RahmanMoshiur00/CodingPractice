//UVa 374
#include<bits/stdc++.h>
using namespace std;

int exp(int x, int n, int m){

    if(n==0) return 1;

    else if(n&1){ //n is odd
        int temp = exp(x, n-1, m);
        return (x%m * temp%m) %m;
    }
    else{ //n is even
        int temp = exp(x, n/2, m);
        return (temp%m * temp%m) % m;
    }
}

/* My implementation; also ACCEPTED. But the other implementation should be used to avoid % overflow

int exp(int x, int n, int m){

    if(n==0) return 1;
    int temp = exp(x, n/2, m);

    if(n&1){ //n is odd
        return (x%m * ((temp%m * temp%m)%m)) % m;
    }
    else{ //n is even
        return (temp%m * temp%m) % m;
    }
}
*/

int main()
{
    int x, n, m;
    while(scanf("%d %d %d", &x, &n, &m) != EOF){
        printf("%d\n", exp(x, n, m));
    }

    return 0;
}
