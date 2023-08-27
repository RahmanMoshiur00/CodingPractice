#include<stdio.h>
#include<string.h>

int main()
{
    int t, l;
    scanf("%d", &t);
    for(l=1; l<=t; l++){
        char str[20000];
        if(l==1) gets(str);
        gets(str);

        char frst[10000], scnd[10000];
        int i, j=0, k=0, count = 0, mark=0;

        for(i=0; i<strlen(str); i++){
            if(str[i]==' '){
                mark = 1;
                continue;
            }
            if(mark==1) scnd[k++] = str[i];
            else frst[j++] = str[i];
        }

        for(i=0; i<strlen(scnd); i++){
            for(j=0; j<strlen(frst); j++){
                if(scnd[i]==frst[j]){
                    frst[j] = '0';
                    count++;
                    break;
                }
            }
        }
        //printf("frst=%s  scnd=%s\n", frst, scnd);
        if(count==strlen(scnd)) printf("Might contain pattern.\n");
        else printf("Doesn't contain pattern.\n");
        printf("\n");
    }
}
