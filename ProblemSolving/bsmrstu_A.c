#include<stdio.h>

int main()
{
    int t, l;
    scanf("%d", &t);
    for(l=1; l<=t; l++){
        scanf("");
        int i, a, b, c, count=0;
        int sign[4]={0};
        scanf("%d %d %d", &a, &b, &c);
        if(a/b==c) sign[0]++;
        if(a*b==c) sign[1]++;
        if(a+b==c) sign[2]++;
        if(a-b==c) sign[3]++;
        char mark[5];
        strcpy(mark, "/*+-");
        int max = sign[0];
        for(i=1; i<4; i++){
            if(max<sign[i]) max = sign[i];
        }
        for(i=0; i<4; i++){
            if(sign[i]!=0){
                printf("%c", mark[i]);
                count++;
                if(count==max) printf("\n");
                else printf(" ");
            }

        }
    }
    return 0;
}
