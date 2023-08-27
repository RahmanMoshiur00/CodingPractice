#include<stdio.h>
#include<string.h>
int main()
{
    int t, l;
    scanf("%d", &t);
    for(l=1; l<=t; l++){

        int position=0, k, now;
        char stak[100][51];
        char command[60];

        strcpy(stak[0], "http://www.lightoj.com/");
        printf("Case %d:\n", l);

        for(k=0; ;k++){
            if(k==0) gets(command);
            gets(command);

            if(strcmp(command, "QUIT")==0){
                break;
            }
            else if(strcmp(command, "BACK")==0){
                position--;
                if(position<0){
                   printf("Ignored\n");
                   position++;
                }
                else{
                    printf("%s\n", stak[position]);
                }
            }
            else if(strcmp(command, "FORWARD")==0){
                position++;
                if(position>now){
                    printf("Ignored\n");
                    position--;
                }
                else printf("%s\n", stak[position]);
            }
            else{
                position++;
                int i, j=0;
                for(i=6; command[i]!='\0'; i++){
                    stak[position][j] = command[i];
                    j++;
                }
                stak[position][j] = '\0';
                now = position;

                printf("%s\n", stak[position]);
            }
        }
    }
    return 0;
}
