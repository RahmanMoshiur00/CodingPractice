#include<stdio.h>
int main()
{
    int t[3][3], a[3][3] = {{1,2,3}, {4,5,6}, {7,8,9}};
    int r=3, i, j;

    printf("\nThe given matrix is given bellow:\n");

    for(i=0; i<r; i++){
        for(j=0; j<r; j++) printf("%d ", a[i][j]);
        printf("\n");

    }

    for(i=0; i<r; i++){
        for(j=0; j<r; j++) t[j][i] = a[i][j];
    }

    printf("\nTranspose matrix is given bellow:\n");

    for(i=0; i<r; i++){
        for(j=0; j<r; j++) printf("%d ", t[i][j]);
        printf("\n");

    }
}
