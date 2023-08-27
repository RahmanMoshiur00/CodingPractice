#include<bits/stdc++.h>
using namespace std;

#define n 1000
vector<int> primes;
vector<bool> checker(n);

void seive(void){

    checker[0] = true;
    checker[1] = true;
    for(int i=2; i<=n; i+=2) checker[i] = true;


    primes.push_back(2);

    int root = sqrt(n+1.0);

    for(int i=3; i<=n; i++){
        if(!checker[i]){
            primes.push_back(i);
            if(i<=root){
                for(int j=i*i; j<=n; j+=i*2) checker[j] = true;
            }
        }
    }
}


int main()
{

    int num;

    while(scanf("%d", num)){
        if(num==0) break;
        int nmbr = abs(num);

        if(num==1) printf("1 = 1\n");
        else if(num==-1) printf("-1 = -1\n");
        else if(num<0) printf("%d = -1 x ", num);
        else printf("%d = ", num);

        seive();

        if(!checker[nmbr]) printf("%d\n", num);
        else{
            vector<int> fectors;

            for(int i=0; primes[i]*primes[i] <= nmbr; i++){
                if(nmbr%primes[i]==0){
                    fectors.push_back(primes[i]);
                    nmbr = nmbr / primes[i];
                    i--;
                }
            }

            for(int i=0; i<fectors.size(); i++){
                if(i==0) printf("%d", fectors[i]);
                else printf(" x %d", fectors[i]);
            }

            printf("\n");
        }
    }

    return 0;
}
