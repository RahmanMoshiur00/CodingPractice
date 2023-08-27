#include<stdio.h>
#include<math.h>

int primeNumbers[300000], numberOfPrimes=0, mark[1000002] = {0};

int sieve(int n)
{
    int i, j, limit = sqrt(n+1.0);
    primeNumbers[numberOfPrimes++] = 2;
    for(i=4; i<=n; i+=2) mark[i] = 1;
    for(i=3; i<=n; i+=2){
        if(!mark[i]){
            primeNumbers[numberOfPrimes++] = i;
            if(i<=limit){
                for(j=i*i; j<=n; j+=i*2) mark[j] = 1;
            }
        }
    }
    return numberOfPrimes;
}

int main()
{
   int n = sieve(100); printf("%d\n", n);
   int i;
   for(i=0; i<n; i++) printf("%d ", primeNumbers[i]);
   return 0;
}
