#include<stdio.h>
int main()
{
    int sh, sm, fh, fm, h, m;
    scanf("%d %d %d %d", &sh, &sm, &fh, &fm);
    if(sh>=fh){
        h = 24 - sh + fh;
    }
    else{
        h = fh - sh;
    }
    if(sm<=fm) m = fm - sm;
    else{
        m = 60 - sm + fm;
        h--;
    }
    printf("O JOGO DUROU %d HORA(S) E %d MINUTO(S)\n", h, m);
}
