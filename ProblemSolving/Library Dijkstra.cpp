

#define rep(i, begin, end) for (__typeof(end) i = (begin) - ((begin) > (end)); i != (end) - ((begin) > (end)); i += 1 - 2 * ((begin) > (end)))
#define INF           1000000007
#define mxn           100010

vector< pair<int, int> > adj[mxn];
bool vis[mxn];
int dist[mxn];    // shortest distance of vertex i from source
int parent[mxn]; // parent of vertex i

void dijkstra(int source) // finds shortest paths from source node s to other nodes present in the graph
{
    rep(i, 0, mxn) vis[i]=false , dist[i]=INF;
    rep(i, 0, mxn) parent[i] = -1;

    dist[source] = 0;
    priority_queue< pair<int,int> > pq;
    pq.push({0, source});

    while(!pq.empty()){
        pair<int,int> p = pq.top(); pq.pop();
        int u = p.second , c = -p.first;

        if(c > dist[u]) continue; // shortest path of vertex u has already been found
     // or
    //  if(vis[u]) continue; // shortest path of vertex u has already been found

        vis[u] = true;

        rep(i, 0, adj[u].size()){
            int v = adj[u][i].first , w = adj[u][i].second;
            if(dist[u]+w < dist[v]){
                dist[v] = dist[u] + w;
                parent[v] = u;
                pq.push({-dist[v], v}); // pushing -dist[v] to find minimum distant node every time from pq
            }
        }
    }
}
