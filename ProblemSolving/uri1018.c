#include<stdio.h>
int main()
{
    int N, i;
    scanf("%d", &N);
    int not[7] = {100.0, 50, 20, 10, 5, 2, 1};
    int not1[7];
    if(N>0 && N<1000000){
        for(i=0; i<7; i++){
            not1[i] = N / not[i];
            N = N % not[i];
        }
        for(i=0; i<7; i++) printf("%d nota(s) de R$ %d,00\n", not1[i], not[i]);
    }
}
