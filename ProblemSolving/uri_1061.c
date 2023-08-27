#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int main()
{
    char stday[10], edday[10];
    int sth, stm, sts, edh, edm, eds;
    gets(stday);
    scanf("%d : %d : %d", &sth, &stm, &sts);
    gets(edday);
    gets(edday);
    scanf("%d : %d : %d", &edh, &edm, &eds);

    char day1[3], day2[3];
    if(strlen(stday)==5){
        day1[0] = stday[4];
        day1[1] = '\0';
    }
    else if(strlen(stday)==6){
        day1[0] = stday[4];
        day1[1] = stday[5];
        day1[2] = '\0';
    }
    if(strlen(edday)==5){
        day2[0] = edday[4];
        day2[1] = '\0';
    }
    else if(strlen(edday)==6){
        day2[0] = edday[4];
        day2[1] = edday[5];
        day2[2] = '\0';
    }


    int std = atoi(day1);
    int edd = atoi(day2);

    int day = edd - std;
    int hour, min, sec;
    if(edh>=sth) hour = edh - sth;
    else if(sth>edh){
        hour = 24 - sth + edh;
        day--;
    }
    if(edm>=stm) min = edm - stm;
    else if(stm>edm){
        min = 60 - stm + edm;
        hour--;
    }
    if(eds>=sts) sec = eds - sts;
    else if(sts>eds){
        sec = 60 - sts + eds;
        min--;
    }
    printf("%d dia(s)\n", day);
    printf("%d hora(s)\n", hour);
    printf("%d minuto(s)\n", min);
    printf("%d segundo(s)\n", sec);

}
