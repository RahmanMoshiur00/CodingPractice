#include<bits/stdc++.h>
using namespace std;

#define MAX 180000
int root = sqrt(MAX);

int main()
{
    int t;
    scanf("%d", &t);

    int n;
    scanf("%d", &n);
    t--;

    vector<int> primes;
    bool checker[MAX];
    primes.push_back(2);
    for(int i=2; i<=MAX; i+=2) checker[i] = true;
    for(int i=3; i<=MAX; i+=2){
        if(checker[i] != true){
            primes.push_back(i);
            if(i<=root) for(int j=i*i; j<=MAX; j+=i*2) checker[j] = true;
        }
    }

    printf("%d\n", primes[n-1]);

    while(t--){
        scanf("%d", &n);
        printf("%d\n", primes[n-1]);
    }

    return 0;
}
