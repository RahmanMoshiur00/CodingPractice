#include<stdio.h>
int main()
{
    int k, j;
    scanf("%d", &j);
    for(k=0; k<j; k++){
        int i = 0, n, num, vs, vf, count = 0;
        int ara[100];
        printf("Enter the decimal number:");
        scanf("%d", &num);
        while(1){
            vs = num % 2;
            ara[i] = vs;
            count++;
            vf = num / 2;
            if(vf == 0) break;
            num = vf;
            i++;
        }
        printf("Respective binary number is:");
        for(n=count-1; n>=0; n--) printf("%d", ara[n]);
        printf("\n");
    }
}

