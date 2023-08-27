#include<stdio.h>
int main()
{
    int t;
    scanf("%d", &t);
    while(t--){
        double kg, ans;
        int count = 0, i;
        scanf("%lf", &kg);
        ans = kg;
        for(i=0; ; i++){
            ans /= 2.0;
            count++;
            if(ans<1.0) break;
        }
        printf("%d days\n", count);
    }
    return 0;
}
