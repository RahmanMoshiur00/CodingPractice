#include<bits/stdc++.h>
using namespace std;

int main()
{
    long long n, one, two, counter=0;
    cin>>n>>one>>two;

    two *= 2;
    for(long long i=0; i<n; i++){
        long long group;
        cin>>group;
        if(group==1){
            if(one>0) one--;
            else if(two>0) two--;
            else counter++;
        }
        else{
            if(two>=2) two-=2;
            else counter += 2;
        }
    }
    cout<<counter<<endl;
    return 0;
}
