#include<stdio.h>
#include<stdlib.h>
int sort(int arr[], int n){
    int i, j, count=0;
    for(i=0; i<n; i++){
        for(j=i+1; j<n; j++){
            if(arr[i]>arr[j]){
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
                count++;
            }
        }
    }
    return count;
}

int main()
{
    int t, l;
    scanf("%d", &t);
    for(l=1; l<=t; l++){
        int n;
        scanf("%d", &n);
        int arr1[n], arr2[n], i;
        for(i=0; i<n; i++) scanf("%d", &arr1[i]);
        for(i=0; i<n; i++) scanf("%d", &arr2[i]);
        int count1, count2;
        count1 = sort(arr1, n);
        count2 = sort(arr2, n);
        printf("Case %d: %d\n", l, abs(count1-count2));
    }
    return 0;
}
