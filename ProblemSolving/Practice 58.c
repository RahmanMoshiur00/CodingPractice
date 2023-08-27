#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <cmath>
using namespace std;
const int MAXN=100010;
int T,n,m,c[MAXN],x,y;
long long a[MAXN];
int main() {
    scanf("%d",&T);
    while(T--){
        scanf("%d%d",&n,&m);
        for(int i=1;i<=n;i++)scanf("%d",&c[i]);
        memset(a,0,sizeof(a));
        while(m--){ scanf("%d%d",&x,&y); a[x]+=y; }
        for(int i=1;i<=n;i++)if(a[i]>c[i])a[i+1]+=a[i]-c[i],a[i]=c[i];
        cout<<a[n+1]<<endl;
        for(int i=1;i<=n;i++){
            printf("%lld", a[i]);
            if(i<n) printf(" ");
            else if(i==n) printf("\n");
        }cout<<a[i]<<" ";
        printf("\n");
    }
    return 0;

}
