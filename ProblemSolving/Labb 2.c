#include <stdio.h>

int main()
{
    int r1, c1, r2, c2, i, j, k;

    printf("Enter row and column of matrix A: ");
    scanf("%d %d", &r1, &c1);

    int A[r1][c1];
    printf("Enter matrix A:\n");
    for(i=0; i<r1; i++){
        for(j=0; j<c1; j++){
            scanf("%d", &A[i][j]);
        }
    }

    printf("Enter row and column of matrix B: ");
    scanf("%d %d", &r2, &c2);

    if(c1 != r2){
        printf("Matrix A and B can not be multiplied!\n");
        return 0;
    }

    int B[r2][c2];
    printf("Enter matrix B:\n");
    for(i=0; i<r2; i++){
        for(j=0; j<c2; j++){
            scanf("%d", &B[i][j]);
        }
    }

    int C[r1][c2];
    for(i=0; i<r1; i++){
        for(j=0; j<c2; j++){
            C[i][j] = 0;
            for(k=0; k<c1; k++){
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }

    printf("Multiplied matrix C:\n");
    for(i=0; i<r1; i++){
        for(j=0; j<c2; j++){
            printf("%d ", C[i][j]);
        }
        printf("\n");
    }

    return 0;
}
