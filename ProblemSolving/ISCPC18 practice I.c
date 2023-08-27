#include<stdio.h>
#include<math.h>

int main()
{
    int t, tc;
    scanf("%d", &tc);

    for(t = 1; t<=tc; t++){
        int n, m, c, b, cost_m, cost_c , cost_b, ans = 0;
        scanf("%d %d %d %d", &n, &m, &c, &b);

        if(n%2==0){
            cost_m = (n/2) * m;
        }
        else{
            cost_m = ((n/2) + 1) * m;
        }

        if(n%4==0){
            cost_c = (n/4) * c;
        }
        else{
            cost_c = ((n/4) + 1) * c;
        }

        if(n%50==0){
            cost_b = (n/50) * b;
        }
        else{
            cost_b = ((n/50) + 1) * b;
        }

        ans = cost_m;
        if(ans > cost_c) ans = cost_c;
        if(ans > cost_b) ans = cost_b;

        printf("%d\n", ans);
    }

    return 0;
}


