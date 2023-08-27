#include<bits/stdc++.h>
using namespace std;
#define white 0
#define gray 1
#define black 2
#define MAX 1000
vector<int> adj[MAX];
int color[MAX];
bool check[MAX];
int d[MAX];
int f[MAX];
stack<int> st;
int Time=1;


void BFS(int source){
    color[source] = gray;
    for(int i=0; i<adj[source].size(); i++){
        int v = adj[source][i];
        if(color[v]==white){
            Time++;
            BFS(v);
        }
    }
    Time++;
    f[source] = Time;
    color[source] = black;
    st.push(source);
}

void topologicalSort(vector<int>& arr){
    for(int i=0; i<arr.size(); i++){
        int u = arr[i];
        if(color[u] == white){
            BFS(u);
        }
    }
}


int main()
{
    cout<<"Enter how many data[edge] you want to enter: ";
    int e, u, v;
    cin>>e;
    vector<int> arr;
    for(int i=0; i<e; i++){
        cin>>u>>v;
        adj[u].push_back(v);

        if(!check[u]){
            arr.push_back(u);
            check[u] = true;
        }
        if(!check[v]){
            arr.push_back(v);
            check[v] = true;
        }
    }
    topologicalSort(arr);

    cout<<"After topological Sort: ";
    while(!st.empty()){
        cout<<st.top()<<" ";
        st.pop();
    }

    return 0;
}
