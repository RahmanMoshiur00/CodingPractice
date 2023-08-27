#include<stdio.h>
int main()
{
    int t, l;
    scanf("%d", &t);
    for(l=1; l<=t; l++){
        int first[3], sec[3], i, ans=0;
        scanf("%d %d %d %d %d %d", &first[0], &first[1], &first[2], &sec[0], &sec[1], &sec[2]);
        long long int result1 = (first[0]*3600) + (first[1]*60) + first[2];
        long long int result2 = (sec[0]*3600) + (sec[1]*60) + sec[2];
        if(result1==result2) printf("Case %d: Yes\n", l);
        else printf("Case %d: No\n", l);
    }
    return 0;
}

