#include <bits/stdc++.h>
using namespace std;

//UVa 929
int r, c;
int grid[1001][1001], dist[1001][1001];
int X[] = {1, 0, -1, 0};
int Y[] = {0, 1, 0, -1};

struct node{
    int w, u, v;
    node(int _w, int _u, int _v){ u = _u, v = _v, w = _w; }
};

struct pq_cmp
{
    bool operator() (node& a, node& b)
    {
        if(a.w == b.w){
            if(a.u == b.u) return (a.v < b.v);
            else return (a.u < b.u);
        }
        else return (a.w < b.w);
    }
};


bool valid(int x, int y)
{
    return !(x<0 or x>=r or y<0 or y>=c);
}

int dijkstra()
{
    for(int i=0; i<r; i++)
        for(int j=0; j<c; j++) dist[i][j] = 1000000000;

    priority_queue<node, vector<node>, pq_cmp> pq;
    dist[0][0] = grid[0][0];
    pq.push({dist[0][0], 0, 0});


    while(!pq.empty()){
        node t = pq.top(); pq.pop();
        int w = t.w, x = t.u, y = t.v;

        cout<<"w = "<<w<<endl;

        if(x==r-1 and y==c-1) return w;

       // if(w > dist[x][y]) continue;


        for(int i=0; i<4; i++){
            int a = x + X[i], b = y + Y[i];
            if(valid(a, b) and dist[x][y]+grid[a][b]<dist[a][b]){
                dist[a][b] = dist[x][y] + grid[a][b];
                pq.push({dist[a][b], a, b});
            }
        }
    }
}

void solve()
{
    cin>>r>>c;
    for(int i=0; i<r; i++){
        for(int j=0; j<c; j++){
            cin>>grid[i][j];
        }
    }

    int ans = dijkstra();
    cout<<ans<<endl;
}

int main()
{
    int tc; cin>>tc;
    while(tc--) solve();
}
