#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    map<int, int> series;
    vector<int> order;

    while(scanf("%d", &n) != EOF){
        if(series[n]==0) order.push_back(n);
        series[n]++;
    }

    for(int i=0; i<order.size(); i++) printf("%d %d\n", order[i], series[order[i]]);

    return 0;
}
