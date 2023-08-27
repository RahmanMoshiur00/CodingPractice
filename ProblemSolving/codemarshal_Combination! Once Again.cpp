#include<bits/stdc++.h>
using namespace std;

long long nCr(int n, int r){

}

int main()
{
    int n, r;
    while((scanf("%d %d", &nn, &nr) == 0) && (nn!=0 && nr!=0))
    {
        vector<int> n(nn);
        int r[nr];
        for(int i=0; i<nn; i++) cin>>n[i];
        for(int i=0; i<nr; i++) scanf("%d", &r[i]);
        n.erase( unique( n.begin(), n.end() ), n.end() );
        int N = n.size();

    }

}
