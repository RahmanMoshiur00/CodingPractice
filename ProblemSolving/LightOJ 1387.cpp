#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    scanf("%d", &t);
    for(int l=1; l<=t; l++){
        printf("Case %d:\n", l);
        int q;
        scanf("%d ", &q);

        int amount = 0;
        while(q--){
            char str[15];
            gets(str);

            if(str[0]=='d'){
                char c[10];
                int tk;
                sscanf(str, "%s %d", c, &tk);
                amount = amount + tk;
            }
            else printf("%d\n", amount);
        }
    }

    return 0;
}
