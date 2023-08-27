#include<stdio.h>
#include<math.h>
int main()
{
    int t;
    scanf("%d", &t);
    while(t--){
        int a, b, c, i, ans = 1;
        scanf("%d %d %d", &a, &b, &c);
        for(i=1; i<=b; i++){
            ans *= a;
            ans %= c;
        }
        printf("Result = %d\n", ans);
    }
    return 0;
}

