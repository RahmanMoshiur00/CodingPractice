#include<bits/stdc++.h>
using namespace std;
#define MAX 1005
#define INF 1000000000

int cost[MAX][MAX];
int parent[MAX];

void initialization(){
    for(int i=0; i<MAX; i++){
        parent[i] = INF;
        for(int j=0; j<MAX; j++){
            if(i==j) cost[i][j] = 0;
            else cost[i][j] = INF;
        }
    }
}

void FloydWarshall(){
    for(int k=0; k<MAX; k++){
        for(int i=0; i<MAX; i++){
            for(int j=0; j<MAX; j++){
                if(cost[i][j] > cost[i][k]+ cost[k][j]){
                    cost[i][j] = cost[i][k]+ cost[k][j];
                    parent[j] = k;
                }
            }
        }
    }
}

void printPath(int s, int n){
    stack<int> path;
    path.push(n);
    while(parent[n] != s){
        n = parent[n];
        path.push(n);
    }
    cout<<" "<<s;
    while(!path.empty()){
        cout<<" "<<path.top();
        path.pop();
    }
    cout<<endl;
}

int main()
{
    int e, u, v, w, q;
    cout<<"Enter how many edge entries you want to have: ";
    cin>>e;
    cout<<"Enter two nodes and their cost(weight of the edge):\n";

    initialization();
    for(int i=0; i<e; i++){
        cin>>u>>v>>w;
        cost[u][v] = w;
    }

    FloydWarshall();

    cout<<"Enter how many shortest path search queries you want to have: ";
    cin>>q;
    cout<<"Enter two nodes you want to find shortest path for:\n";
    for(int i=0; i<q; i++){
        cin>>u>>v;
        if(cost[u][v] != INF){
            cout<<"Shortest path cost between "<<u<<" and "<<v<<" is: "<<cost[u][v]<<endl;
            //don't know why printPath function isn't working properly! -_-
            //cout<<"Path: ";
            //printPath(u, v);
        }
        else cout<<"There is no path from "<<u<<" to "<<v<<endl;
    }

    return 0;
}
