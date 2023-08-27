#include<bits/stdc++.h>
using namespace std;
typedef long long intt;
#define ff              first
#define ss              second
#define pb              push_back
#define mp              make_pair
#define DUMMY           ios_base::sync_with_stdio(false);cin.tie(NULL);
#define SQ(a)           ((a)*(a))
#define MX              1000005

vector<intt> primes;
bool check[MX];
map<intt, intt> indx;
vector< vector<intt> > ans;
vector<intt> extra;

void sieve(intt n){
    intt counter=0;
    check[0] = check[1] = true;
    primes.pb(2);
    indx[2] = counter++;;
    for(intt i=2; i<=n; i+=2) check[i] = true;
    intt rt = sqrt(n) + 2;
    for(intt i=3; i<=n; i+=2){
        if(!check[i]){
            primes.pb(i);
            indx[i] = counter++;
            if(i<=rt){
                for(intt j=i*i; j<=n; j += i*2) check[j] = true;
            }
        }
    }
}

void printDetPrimes(intt l, intt u){

    intt li=-1, ui=-1;

    while(li==-1 || ui==-1){ //finding the indexes of vector<intt>primes between the l...u range
        if((!check[l]) && li==-1) li = indx[l];
        if((!check[u]) && ui==-1) ui = indx[u];
        l++;
        u--;
    }

    intt dist, i, j, counter=3;
    for(i=li; i<=ui-2; i++){ //storing the determinate prime series(s)
        if((primes[i+1]-primes[i]) == (primes[i+2] - primes[i+1])){
            extra.pb(primes[i]);
            extra.pb(primes[i+1]);
            extra.pb(primes[i+2]);
            dist = primes[i+1]-primes[i];
            counter = 3;
            for(j = i+2; j<=ui-1; j++){
                if(primes[j+1]-primes[j]==dist){
                    extra.pb(primes[j+1]);
                    counter++;
                }
                else break;
            }
            ans.pb(extra);
            extra.clear();
            i += counter-1;
        }
    }

    intt sz = ans.size();
    if(((primes[ui+1]-primes[ui]) == (primes[ui]-primes[ui-1])) && ((primes[ui]-primes[ui-1]) == (primes[ui-1] - primes[ui-2]))) sz--; //if uni-distance series of primes contains more primes out of the range, then the last series should be eliminated

    for(intt i=0; i<sz; i++){ //printing all the valid determinate prime series(s)
        intt s = ans[i].size();
        for(intt j=0; j<s; j++){
            if(j==0) cout<<ans[i][j];
            else if(j==s-1) cout<<" "<<ans[i][j]<<endl;
            else cout<<" "<<ans[i][j];
        }
    }
    ans.clear();
}

int main()
{
    DUMMY

    sieve(MX);

    intt l, u;
    while(cin>>l>>u){
        if(l==0 && u==0) break;
        if(l>u) swap(l,u);
        printDetPrimes(l, u);
    }

    return 0;
}
