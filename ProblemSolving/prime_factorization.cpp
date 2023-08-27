#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    while(scanf("%d", &n), n){
        if(n<0) printf("%d = -1 x ", n), n = abs(n);
        else printf("%d = ", n);

        int Copy = n;

        vector<int> factors;
        for(int i=2; i*i<=n; i++){
            while(n%i==0){
                factors.push_back(i);
                n /= i;
            }
        }
        if(n != 1) factors.push_back(n);



        for(int i=0; i<factors.size(); i++){
            if(i==0) printf("%d", factors[i]);
            else printf(" x %d", factors[i]);
        }
        printf("\n");

        int counter = 1;
        printf("%d = ", Copy);

        for(int i=0, j=0; i<factors.size(); i++){
            if(factors[i]==factors[i+1]) counter++;
            else{
                if(j>0) printf(" x ");
                printf("%d^%d", factors[i], counter);
                counter = 1;
                j++;
            }
        }
        printf("\n");
    }

    return 0;
}

