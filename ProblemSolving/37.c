#include<stdio.h>
int main()
{
    int a[3][3] = {{1,2,3}, {4,5,6}, {7,8,9}}, t[3][3] = {{11,12,13}, {14,15,16}, {17,18,19}};
    int add[3][3];
    int r=3, i, j;

    printf("The first given matrix is:\n");

    for(i=0; i<r; i++){
        for(j=0; j<r; j++) printf("%d ", a[i][j]);
        printf("\n");
    }

    printf("The second given matrix is:\n");

    for(i=0; i<r; i++){
        for(j=0; j<r; j++) printf("%d ", t[i][j]);
        printf("\n");
    }

    for(i=0; i<r; i++){
        for(j=0; j<r; j++) add[i][j] = t[i][j] + a[i][j];
    }


    printf("After adding the matrics:\n");

    for(i=0; i<r; i++){
        for(j=0; j<r; j++) printf("%d ", add[i][j]);
        printf("\n");
    }

}
