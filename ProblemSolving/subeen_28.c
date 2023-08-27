#include<stdio.h>
int main()
{
    int t;
    scanf("%d", &t);
    while(t--){
        int n;
        scanf("%d", &n);
        int arr[n], check=0, i;
        for(i=0; i<n; i++) scanf("%d", &arr[i]);
        if(arr[0]<arr[1]){
            for(i=1; i<n-1; i++){
                if(arr[i]>arr[i+1]){
                    check = 1;
                    printf("NO\n");
                    goto end;
                }
            }
        }
        if(arr[0]>arr[1]){
            for(i=1; i<n-1; i++){
                if(arr[i]<arr[i+1]){
                    printf("NO\n");
                    goto end;
                }
            }
        }
        printf("YES\n");
        end:
            printf("");
    }
}
