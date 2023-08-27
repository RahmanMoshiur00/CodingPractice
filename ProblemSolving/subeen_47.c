#include<stdio.h>
int main()
{
    int t;
    scanf("%d", &t);
    while(t--){
        int n1, n2, i, j=0;
        scanf("%d", &n1);
        int arr1[n1];
        for(i=0; i<n1; i++) scanf("%d", &arr1[i]);
        scanf("%d", &n2);
        int arr2[n2];
        for(i=0; i<n2; i++) scanf("%d", &arr2[i]);
        int arr[n1+n2];
        for(i=0; i<n1; i++){
            arr[j++] = arr1[i];
        }
        for(i=0; i<n2; i++){
            arr[j++] = arr2[i];
        }
        for(i=0; i<n1+n2; i++){
            for(j=i; j<n1+n2; j++){
                if(arr[i]>arr[j]){
                    int a = arr[i];
                    arr[i] = arr[j];
                    arr[j] = a;
                }
            }
        }
        for(i=0; i<n1+n2; i++){
            printf("%d", arr[i]);
            if(i!=(n1+n2-1)) printf(" ");
            else printf("\n");
        }
    }
    return 0;
}
