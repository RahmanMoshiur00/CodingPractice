#include<stdio.h>
int main()
{
    int count=0;
    double score, sum=0.0;
    start:
    count=0; sum = 0.0;
    while(scanf("%lf", &score)==1){
        if(score>=0.0 && score<=10.0){
            count++;
            sum += score;
        }
        else printf("nota invalida\n");
        if(count==2) break;
    }
    printf("media = %.2lf\n", sum/2.0);
    command:
    printf("novo calculo (1-sim 2-nao)\n");
    int com;
    scanf("%d", &com);
    if(com==1) goto start;
    else if(com!=2) goto command;
    else if(com==2) goto end;
    end:
        return 0;


}
