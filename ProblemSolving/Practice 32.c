#include<stdio.h>

int main(){
    int a[5] = {3, 7, 2, 14, 9};
    int i, j, temp;
    int n = 5; //n = length of the array

    printf("Unsorted array: ");
    for (i = 0; i < n; i++) {
      printf("%d ", a[i]);
    }

    for (i = 0; i < n-1; i++) {
      for (j = 0; j < n - 1; j++) {
         if (a[j] > a[j + 1]) {
            temp = a[j];
            a[j] = a[j + 1];
            a[j + 1] = temp;
         }
      }
    }

    printf("\nAfter sorting: ");
    for(i=0; i<n; i++) printf("%d ", a[i]);
}
