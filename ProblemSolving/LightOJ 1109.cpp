#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    vector<int> divisor[1000];
    scanf("%d", &t);
    for(int i=1; i<=1000; i++){
        for(int j=i; j<=1000; j+=i){
            divisor[j].push_back(i);
        }
    }
    for(int i=1; i<=1000; i++){
        for(int j=i+1; j<=1000; j++){
            if(divisor[i].size() > divisor[j].size()) swap(divisor[i].size(), divisor[j].size());
            else if((divisor[i].size() == divisor[j].size()) && (i<j)) swap(divisor[i].size(), divisor[j].size());
        }
    }
    for(int l=1; l<=t; l++){
        int n;
        scanf("%d", &n);
        cout<<"Case "<<l<<": "<<divisor[n].size()<<endl;
    }
    return 0;
}
