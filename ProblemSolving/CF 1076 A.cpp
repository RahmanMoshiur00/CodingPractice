#include<bits/stdc++.h>
using namespace std;


int main()
{
    int n; cin>>n;
    string str; cin>>str;

    int idx = 0;
    for(int i=1; i<str.size(); i++){
        if(str[idx]>str[i]){
            break;
        }
        else{
            idx = i;
        }
    }
    for(int i=0; i<str.size(); i++){
        if(i != idx) cout<<str[i];
    }

    return 0;
}
