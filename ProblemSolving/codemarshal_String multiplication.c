#include<stdio.h>
#include<string.h>

int main()
{
    int i, t;
    scanf("%d", &t);
    for(i=1; i<=t; i++){
        char str[1000001];
        char syl[53] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
        int nos[52] = {0};
        int sorted[52];
        int j, k, l, min, sum=0;
        scanf("%s", str);
        for(j=0; j<strlen(str); j++){
            for(k=0; k<52; k++){
                if(str[j]==syl[k]){
                    nos[k] += 1;
                    break;
                }
            }
        }

        for(j=0, k=0; j<52; j++){
            if(nos[j]!=0){
                sorted[k] = nos[j];
                k++;
            }
        }
        min = sorted[0];
        for(j=1; j<k; j++){
            if(sorted[j]<min) min = sorted[j];
        }

        for(j=0; j<52; j++){
            if(nos[j] != 0) sum += (nos[j] / min);
        }

        for(j=0; j<sum; j++) printf("%c", str[j]);
        printf("\n");
    }

    return 0;
}
