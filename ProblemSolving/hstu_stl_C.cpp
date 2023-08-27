#include<bits/stdc++.h>
using namespace std;

int main()
{
    map<string, string> slogan;
    int t;
    scanf("%d ", &t);
    while(t--){
        char key[101], value[101];
        gets(key);
        gets(value);
        slogan[key] = value;
    }
    int q;
    scanf("%d ", &q);
    while(q--){
        char quote[101];
        gets(quote);
        cout<<slogan[quote]<<endl;
    }
    return 0;
}
