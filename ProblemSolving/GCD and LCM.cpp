#include<bits/stdc++.h>
using namespace std;
#define intt long long

intt GCD(intt a, intt b){
    intt temp;
    while(a!=0){
        temp = a;
        a = b%a;
        b = temp;
    }
    return b;
}

intt LCM(intt a, intt b){ //this function is used to handle {(0*0)=0/gcd(0,0)=0} which cause program crush
    if(a==0 && b==0) return 0;
    else return (a*b) / GCD(a,b);
}

int main()
{
    intt x, y, q;
    /*
    Input:
    3
    100 0
    76346 874367
    0 0
    Output:
    GCD=100 LCM=0
    GCD=1 LCM=66754422982
    GCD=0 LCM=0
    */
    cin>>q;
    while(q--){
        cin>>x>>y;
        cout<<"Using user defined function: GCD("<<x<<", "<<y<<") = "<<GCD(x, y)<<endl;
        cout<<"Using built-in function: GCD("<<x<<", "<<y<<") = "<<__gcd(x, y)<<endl;
        cout<<"Using user defined function: LCM("<<x<<", "<<y<<") = "<<LCM(x, y)<<endl;
        cout<<"Using built-in function: GCD("<<x<<", "<<y<<") = "<<(x*y) / __gcd(x, y)<<endl; //program will be crushed for a=0 b=0 in this line; because gcd(0,0)=0
    }

    /*Problem: Check if x and y are relatively prime or not
    Input:
    3
    21 10
    0 1
    4 16
    Output:
    YES
    YES
    NO
    */
    cin>>q;
    while(q--){
        cin>>x>>y;
        if(__gcd(x, y)==1) cout<<"YES\n";
        else cout<<"NO\n";
    }

    return 0;
}
