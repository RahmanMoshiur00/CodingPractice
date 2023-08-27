#include<stdio.h>
long long facto(int n){
    long long count = 1, i;
    for(i=2; i<=n; i++) count *= i;
    return count;
}
int main()
{
    int t;
    scanf("%d", &t);
    while(t--){
        int n, i;
        scanf("%d", &n);
        double count = 0.0;
        for(i=1; i<=n; i++){
            count += (i*1.0) / facto(i);
        }
        printf("%.4lf\n", count);
    }
    return 0;
}

