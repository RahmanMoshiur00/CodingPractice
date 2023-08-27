#include<bits/stdc++.h>
using namespace std;
#define MAX 100

int rep[MAX];
int Rank[MAX];

void MakeSet(){
    for(int i=0; i<MAX; i++){
        rep[i] = i;
        Rank[i] = 0;
    }
}

int FindRepresentative(int x){
    if(x == rep[x]) return x;
    rep[x] = FindRepresentative(rep[x]);
    return rep[x];
}

void Union(int x, int y){
    int RX = FindRepresentative(x);
    int RY = FindRepresentative(y);
    if(RX != RY){
        if(Rank[RX]>Rank[RY]) rep[RY] = RX;
        else{
            rep[RX] = RY;
            if(Rank[RX]==Rank[RY]) Rank[RY]++;
        }
    }
}

bool isSameComponent(int x, int y){
    if(FindRepresentative(x) == FindRepresentative(y)) return true;
    else return false;
}

int main()
{
    MakeSet();
    cout<<"Enter how many entries you want to put: ";
    int n; cin>>n;
    int x, y;
    for(int i=0; i<n; i++){
        cin>>x>>y;
        Union(x, y);
    }
    cout<<"Enter how many queries you want to have: ";
    cin>>n;
    for(int i=0; i<n; i++){
        cin>>x>>y;
        if(isSameComponent(x, y)) cout<<x<<" and "<<y<<" are same components\n";
        else cout<<x<<" and "<<y<<" are NOT same components\n";
    }

    return 0;
}
