#include<stdio.h>
#include<math.h>

int main()
{
    int t;
    scanf("%d", &t);
    while(t--){
        long long n;
        scanf("%lld", &n);
        double root = sqrt((double)n);
        int ro = (int) root;
        if((double)ro == root) printf("YES\n");
        else printf("NO\n");
    }
    return 0;
}
