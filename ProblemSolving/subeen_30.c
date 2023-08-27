#include<stdio.h>

int main()
{
    int t;
    scanf("%d", &t);
    while(t--){
        long long n;
        scanf("%lld", &n);
        int i, count = 0;
        long long mark[] = {6, 28, 496, 8128, 33550336, 8589869056, 137438691328, 2305843008139952128};
        for(i=0; i<8; i++){
            if(mark[i]==n) count = 1;
        }
        if(count==1) printf("YES, %lld is a perfect number!\n", n);
        else printf("NO, %lld is not a perfect number!\n", n);
    }
    return 0;
}
