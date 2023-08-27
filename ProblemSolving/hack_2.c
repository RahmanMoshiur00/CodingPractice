#include<stdio.h>
#include<stdlib.h>
/*
long long cmpfunc (const void * a, const void * b)
{
   return ( *(long long*)a - *(long long*)b );
}
*/
int main()
{
    int n;
    scanf("%d", &n);
    long long arr[n], i;
    for(i=0; i<n; i++) scanf("%lld", &arr[i]);
    //qsort(arr, n, sizeof(long long), cmpfunc);
    int count = 0, j;
    for(i=1; ; i++){
        for(j=0; j<n; j++){
            if(arr[j]%i != 0) count++;
            if(count>1){
                count = 0;
                break;
            }
        }
        if(count==1){
            printf("%lld\n", i);
            break;
        }
    }
    return 0;
}
