#include<bits/stdc++.h>
using namespace std;
#define white 0
#define gray 1
#define black 2
#define MAX 20001

int color[MAX];
vector<int> adj[MAX];
queue<int> Q;
set<int> nodes;
int gray_counter = 0;
int black_counter = 0;
long long ans = 0;

int main()
{
    int t, n, u, v;
    scanf("%d", &t);
    for(int tc=1; tc<=t; tc++){
        scanf("%d", &n);

        for(int i=0; i<n; i++){
            scanf("%d %d", &u, &v);
            adj[u].push_back(v);
            adj[v].push_back(u);
            nodes.insert(u);
            nodes.insert(v);
        }


        for(set<int>::iterator it=nodes.begin(); it!=nodes.end(); it++){
            int node = *it;
            gray_counter = black_counter = 0;
            if(color[node]==white){ //BFS starts
                color[node] = gray;
                gray_counter++;

                Q.push(node);

                while(!Q.empty()){
                    u = Q.front();
                    Q.pop();
                    int sz = adj[u].size();
                    for(int i=0; i<sz; i++){
                        v = adj[u][i];
                        if(color[v]==white){
                            Q.push(v);
                            if(color[u]==gray){
                                color[v] = black;
                                black_counter++;
                            }
                            else{
                                color[v] = gray;
                                gray_counter++;
                            }
                        }
                    }
                }
                ans += (long long)max(gray_counter, black_counter);
            }
        }

        printf("Case %d: %lld\n", tc, ans);
        ans = gray_counter = black_counter = 0;

        for(int i=0; i<MAX; i++){
            color[i] = white;
            adj[i].clear();
        }

        nodes.clear();
    }

    return 0;
}
