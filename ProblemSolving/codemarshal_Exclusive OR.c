#include<stdio.h>
unsigned int decToBin(int num, int bin[])
{
    int i, j, k;
    bin[0] = 0;
    for(i=0; num!=0; i++){
        bin[i] = num % 2;
        num = num / 2;
    }
    /*for(i=0, k=j-1; i<=j/2; i++, k--){
        int temp = bin[k];
        bin[k] = bin[i];
        bin[i] = temp;
    }*/
    return i;
}
unsigned int add(int bin1[], int len1, int bin2[], int len2, int result[])
{
    int i, j, len;
    if(len1>len2) len = len1;
    else len = len2;
    for(i=0; i<len; i++){
        if(bin1[i]==0 && bin2==0) result[i] = 0;
        else if(bin1[i]==1 && bin2[i]==1) result[i] = 1;
        else result[i] = 1;
    }
    return len;
}
main()
{
    unsigned int n, i;
    int num[100000];
    scanf("%u", &n);
    for(i=0; i<n; i++){
        scanf("%d", &num[i]);
    }

    int bin1[num[i]], bin2[num[i+1]], result[num[i]+num[i+1]];
    /*for(i=0; i<n; i++){
        int bin1[num[i]], bin2[num[i+1]], result[num[i]+num[i+1]];
        unsigned int len = decToBin(num[0], bin1[]);

    }*/

    unsigned int len1 = decToBin(num[0], bin1);
    unsigned int len2 = decToBin(num[1], bin2);
    unsigned int len = add(bin1, len1, bin2, len2, result);
    for(i=len-1; i>=0; i--){
        printf("%d", result[i]);
    }
    printf("\n");
}
