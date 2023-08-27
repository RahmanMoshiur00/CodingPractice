#include<stdio.h>
#include<math.h>
int main()
{
    int num1, num2, i, j, k;
    scanf("%d%d", &num1, &num2);

    int sq1 = sqrt(num1);
    int sq2 = sqrt(num2);
    int a[sq1], b[sq2];


    for(i=2, j=0; num1 != 0; i++){
        if(num1%i==0){
            a[j] = i;
            num1 = num1 / i;
            j++;
            i=1;
        }
    }

    for(i=0; i<j; i++) printf("%d ", a[i]);
    printf("\n");

    for(i=2, k=0; num2 != 0; i++){
        if(num2%i==0){
            b[k] = i;
            num2 = num2 / i;
            k++;
            i=1;
        }
    }

    for(i=0; i<k; i++) printf("%d ", b[i]);

}
