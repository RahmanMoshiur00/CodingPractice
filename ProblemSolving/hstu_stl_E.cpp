#include<bits/stdc++.h>
using namespace std;

int main()
{
    int a, b;
    scanf("%d %d", &a, &b);

    map<string, int> money;

    for(int i=0; i<a; i++){
        char name[17];
        int dollar;
        scanf("%s %d", name, &dollar);
        money[name] = dollar;
    }

    for(int i=0; i<b; i++){
        string description;
        long long total = 0;

        while(cin>>description && description!="."){
            total += money[description];
        }

        printf("%lld\n", total);
    }
    return 0;
}
