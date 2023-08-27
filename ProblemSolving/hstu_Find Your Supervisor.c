#include<stdio.h>

int main()
{
    int t, x;
    scanf("%d", &t);

    for(x=1; x<=t; x++){
        int tcr, std, team, j=0, i;
        scanf("%d %d", &tcr, &std);
        if(std%2==0) team = std/2;
        else team = (std/2) + 1;
        int mark[20] = {0};
        for(i=1; i<=team; i++){
            if(j==tcr) j=0;
            mark[j]++;
            j++;
        }

        printf("%d %d\n", mark[0], mark[tcr-1]);
    }
    return 0;
}
