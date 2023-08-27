#include<stdio.h>
int main()
{
    int t;
    scanf("%d", &t);
    while(t--){
        int n, i, j;
        scanf("%d", &n);
        int arr[n-1];
        for(i=0; i<n-1; i++) scanf("%d", &arr[i]);
        for(i=0; i<n-1; i++){
            for(j=i; j<n-1; j++){
                if(arr[i]>arr[j]){
                    int a = arr[i];
                    arr[i] = arr[j];
                    arr[j] = a;
                }
            }
        }
        for(i=0; i<n; i++){
            if((i+1)!=arr[i]){
                printf("%d\n", i+1);
                break;
            }
        }
    }
    return 0;
}
