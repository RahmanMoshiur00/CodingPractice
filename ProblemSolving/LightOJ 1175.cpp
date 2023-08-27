#include <bits/stdc++.h>
using namespace std;
#define INPUT         freopen("input.txt","r",stdin);
#define OUTPUT        freopen("output.txt","w",stdout);
#define rep(i, begin, end) for (__typeof(end) i = (begin) - ((begin) > (end)); i != (end) - ((begin) > (end)); i += 1 - 2 * ((begin) > (end)))
#define mem(a,v)      memset((a), v, sizeof(a))
#define mxn           205


vector<string> s;
bool fvis[mxn][mxn], jvis[mxn][mxn];
int r, c;
int X[] = {1, 0, -1, 0};
int Y[] = {0, 1, 0, -1};

struct node{
    int i, j, l;
    node(int x, int y, int z){ i=x , j=y , l=z; }
};

queue< node > fire;

bool valid_fire(int i, int j){
    return !(i<0 or i>=r or j<0 or j>=c or fvis[i][j] or s[i][j]=='#' or s[i][j]=='F');
}
bool valid_jane(int i, int j){
    return (!fvis[i][j] and !jvis[i][j] and s[i][j]=='.');
}
bool outOfMaze(int i, int j){
    return (i<0 or i>=r or j<0 or j>=c);
}

int bfs(int jx, int jy)
{
    int x, y, l, fire_level, jane_level;

    jvis[jx][jy] = true;

    queue< node > jane;
    jane.push({jx, jy, 0});

    while(!jane.empty()){
        if(!fire.empty()) fire_level = fire.front().l;
        while(!fire.empty()){
            x = fire.front().i , y = fire.front().j , l = fire.front().l;
            if(fire_level != l) break;
            fire.pop();

            rep(i, 0, 4){
                if(valid_fire(x+X[i], y+Y[i])) fvis[x+X[i]][y+Y[i]] = true , fire.push({x+X[i] , y+Y[i] , l+1});
            }
        }

        jane_level = jane.front().l;
        while(!jane.empty()){
            x = jane.front().i , y = jane.front().j , l = jane.front().l;

            if(jane_level != l) break;
            jane.pop();

            rep(i, 0, 4){
                if(outOfMaze(x+X[i] , y+Y[i])) return l+1;
                else if(valid_jane(x+X[i] , y+Y[i])) jvis[x+X[i]][y+Y[i]] = true , jane.push({x+X[i], y+Y[i], l+1});
            }
        }
    }

    return -1;
}

void solve(int t)
{
    cin>>r>>c;
    s.resize(r);

    rep(i, 0, r) cin>>s[i];

    int jx, jy;

    fire = queue<node>();
    mem(jvis, 0) , mem(fvis, 0);

    rep(i, 0, r){
        rep(j, 0, c){
            if(s[i][j] == 'J') jx = i , jy = j;
            else if(s[i][j] == 'F'){
                fire.push({i, j, 0});
                fvis[i][j] = true;
            }
        }
    }

    int ans = bfs(jx, jy);

    if(ans == -1) cout<<"Case "<<t<<": IMPOSSIBLE"<<endl;
    else cout<<"Case "<<t<<": "<<ans<<endl;

    s.clear();
}

int main()
{
    //INPUT
    int tc; cin>>tc;

    rep(t, 1, tc+1) solve(t);

    return 0;
}


