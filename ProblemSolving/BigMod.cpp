#include<bits/stdc++.h>
using namespace std;

#define intt long long

intt remainder(string& num, intt n){
    intt remainder = 0;
    for(int i=0; num[i]!='\0'; i++) remainder = ( (remainder*10) + (num[i]-'0') ) % n;
    return remainder;
}

int main()
{
    string num;
    intt n, remainder=0;
    cin>>num>>n;

    cout<<remainder(num, n)<<endl;


}
