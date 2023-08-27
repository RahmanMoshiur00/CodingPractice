#include<stdio.h>
int main()
{
    int N, i;
    scanf("%d", &N);
    int not[3] = {3600, 60, 1};
    int not1[3];
    for(i=0; i<3; i++){
        not1[i] = N / not[i];
        N = N % not[i];
    }
    printf("%d:%d:%d\n", not1[0], not1[1], not1[2]);
}
