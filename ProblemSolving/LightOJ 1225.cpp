#include<bits/stdc++.h>
using namespace std;

int main()
{
    int tc;
    scanf("%d ", &tc);
    for(int l=1; l<=tc; l++){
        char num[12];
        scanf("%s", num);
        int Size = strlen(num);
        int mark = 1;
        for(int i=0, j=Size-1; i<Size/2; i++, j--){
            if(num[j]!=num[i]){
                mark = 0;
                break;
            }
        }
        if(mark==1) printf("Case %d: Yes\n", l);
        else printf("Case %d: No\n", l);
    }
    return 0;
}
