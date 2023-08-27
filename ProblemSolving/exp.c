int dec_to_binary(num)
{
    int i = 0, j = 0, n, vs, vf, count = 0;
    int ara[100], ara2[100];
    while(1){
            vs = num % 2;
            ara[i] = vs;
            count++;
            vf = num / 2;
            if(vf == 0) break;
            num = vf;
            i++;
    }
    for(n=count-1; n>=0; n--){
        ara2[j] = ara[n];
        j++;
    }
    return ara2;
}

#include<stdio.h>
int main()
{
    int dec;
    printf("Entaer the decimal numbe:");
    scanf("%d", dec);
    int m = dec_to_binary(dec);
    printf("%d", m);
}
