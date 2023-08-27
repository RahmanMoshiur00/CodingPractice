#include<stdio.h>
#include<math.h>
int main()
{
    int t;
    scanf("%d", &t);
    while(t--){
        int x, k, i;
        double count = 1.0;
        scanf("%d %d", &x, &k);
        for(i=1; i<=k; i++){
            count += pow(x, i);
        }
        printf("Result = %.0lf\n", count);
    }
    return 0;
}
