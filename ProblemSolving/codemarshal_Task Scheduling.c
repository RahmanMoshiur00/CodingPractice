#include<stdio.h>
int main()
{
    unsigned long nor, noq, nday, i, j;
    scanf("%lu", &nor);
    unsigned long range[nor][2];
    for(i=0; i<nor; i++){
        for(j=0; j<2; j++) scanf("%lu", &range[i][j]);
    }
    scanf("%lu", &noq);
    for(i=0; i<noq; i++){
        scanf("%lu", &nday);
        int temp =  0;
        for(j=0; j<nor; j++){
            if(nday>=range[j][0] && nday<=range[j][1]){
                temp = 1;
                break;
            }
        }
        if(temp==1) printf("YES\n");
        else if(temp==0) printf("NO\n");
    }
    return 0;
}
