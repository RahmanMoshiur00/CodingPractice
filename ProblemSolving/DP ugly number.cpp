#include<bits/stdc++.h>
using namespace std;

int nthUglyNumber(int n, int ugly[]){

    ugly[1] = 1;
    int i2=1, i3=1, i5=1;
    int next_multiple_of_2 = 2;
    int next_multiple_of_3 = 3;
    int next_multiple_of_5 = 5;

    for(int i=2; i<=n; i++){
        ugly[i] = min(next_multiple_of_2, min(next_multiple_of_3 , next_multiple_of_5));
        if(ugly[i] == next_multiple_of_2){
            i2++;
            next_multiple_of_2 = ugly[i2] * 2;
        }
        if(ugly[i] == next_multiple_of_3){
            i3++;
            next_multiple_of_3 = ugly[i3] * 3;
        }
        if(ugly[i] == next_multiple_of_5){
            i5++;
            next_multiple_of_5 = ugly[i5] * 5;
        }
    }

    return ugly[n];
}

int main()
{
    int n; cin>>n;
    int ugly[n+1];

    cout<<"Nth ugly number is: "<<nthUglyNumber(n, ugly)<<endl;
    cout<<"Printing all ugly 1st to nth ugly numbers: ";
    for(int i=1; i<=n; i++) cout<<ugly[i]<<" ";
    cout<<endl;

    return 0;
}
