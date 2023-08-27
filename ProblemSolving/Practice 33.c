#include<stdio.h>
int main()
{
    int a[5] = {3, 7, 2, 14, 9};
    int i, j, m, temp;
    int n = 5; //n = length of the array

    printf("Unsorted array: ");
    for (i = 0; i < n; i++) {
      printf("%d ", a[i]);
    }

    for(i=0; i<n-1; i++){
        m = i;
        for(j=i+1; j<n; j++){
            if(a[m]>a[j]){
                m = j;
            }
        }
        temp = a[m];
        a[m] = a[i];
        a[i] = temp;
    }

    printf("\nAfter sorting: ");

    for(i=0; i<5; i++) printf("%d ", a[i]);
}
