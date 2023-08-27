#include<stdio.h>
int main()
{
    int i, g, j, count=0, inter=0, gremio=0, draw=0;
    for(j=0; ; j++){
        scanf("%d %d", &i, &g);
        count++;
        if(i>g) inter++;
        else if(i==g) draw++;
        else gremio++;
        printf("Novo grenal (1-sim 2-nao)\n");
        int com;
        scanf("%d", &com);
        if(com==1) continue;
        else break;
    }
    printf("%d grenais\n", count);
    printf("Inter:%d\n", inter);
    printf("Gremio:%d\n", gremio);
    printf("Empates:%d\n", draw);
    if(inter==gremio) printf("Nao houve vencedor\n");
    else if(inter>gremio) printf("Inter venceu mais\n");
    else printf("Gremio venceu mais\n");

}
