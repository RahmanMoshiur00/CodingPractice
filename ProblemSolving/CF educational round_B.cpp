#include<bits/stdc++.h>
using namespace std;

int main()
{
    long long n, k;
    scanf("%lld %lld", &n, &k);
    long long arr[n];
    for(int i=0; i<n; i++) scanf("%lld", &arr[i]);
    long long sum = 0, i, j, ch;
    if(k==1){
        for(i=0; i<n; i++){
            ch = i + k;
            for(j=i; j<ch; j++) if(j<n) sum += arr[j];
        }

        double res = 0.0;
        int m = (n - k) + 1;

        res = (double)sum / (double)(m*1.0);
        printf("%.10lf\n", res);
    }
    else if(n != 1){
        for(i=0; i<n-1; i++){
            ch = i + k;
            for(j=i; j<ch; j++) if(j<n) sum += arr[j];
        }

        double res = 0.0;
        int m = (n - k) + 1;

        res = (double)sum / (double)(m*1.0);
        printf("%.10lf\n", res);
    }
    else printf("%.10lf\n", (double)arr[0]*1.0);

    return 0;
}
