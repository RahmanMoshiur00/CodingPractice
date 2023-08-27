#include<stdio.h>

int main()
{
    int n, i, j, k;
    scanf("%d", &n);
    int arr[n+1];
    arr[0] = 0;
    for(i=1; i<n+1; i++) scanf("%d", &arr[i]);
    for(i=1; i<n+1; i++){
        for(j=1; j<=n; j++){
            if(i==arr[j]){
                for(k=1; k<=n; k++){
                    if(j==arr[k]) printf("%d\n", k);
                }
            }
        }
    }

    return 0;
}
