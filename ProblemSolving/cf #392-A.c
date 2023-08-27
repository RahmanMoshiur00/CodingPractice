#include<stdio.h>
int main()
{
    int n, i;
    scanf("%d", &n);
    long long arr[n];
    for(i=0; i<n; i++) scanf("%lld", &arr[i]);
    long long max = arr[0], count=0;
    for(i=1; i<n; i++){
        if(arr[i]>max) max = arr[i];
    }
    for(i=0; i<n; i++){
        count += max - arr[i];
    }
    printf("%lld\n", count);
    return 0;
}
