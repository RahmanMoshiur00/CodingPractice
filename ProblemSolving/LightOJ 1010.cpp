#include<bits/stdc++.h>
using namespace std;

int calculate(int notTwo){
    if(notTwo%2==0) return notTwo += notTwo % 4;
    else return notTwo+1;
}

int main()
{
    int tc;
    scanf("%d", &tc);
    for(int l=1; l<=tc; l++){
        int rw, clm, ans;
        scanf("%d %d", &rw, &clm);
        if(rw==1 || clm==1) ans = rw*clm;
        else if(rw==2 || clm==2){
            if(rw==2) ans = calculate(clm);
            else ans = calculate(rw);
        }
        else{
            if((rw*clm)%2==0) ans = (rw*clm) / 2;
            else ans = ((rw*clm)/2)+1;
        }
        printf("Case %d: %d\n", l, ans);
    }
    return 0;
}
