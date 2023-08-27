#include<stdio.h>

int main()
{
    int t, l;
    scanf("%d", &t);
    for(l=1; l<=t; l++){
        int num[3], i, j;
        for(i=0; i<3; i++) scanf("%d", &num[i]);
        for(i=0; i<3; i++){
            for(j=i+1; j<3; j++){
                if(num[i]>num[j]){
                    int a = num[i];
                    num[i] = num[j];
                    num[j] = a;
                }
            }
        }
        printf("Case %d: ", l);
        for(i=0; i<3; i++){
            printf("%d", num[i]);
            if(i==2) printf("\n");
            else printf(" ");
        }
    }
    return 0;

}
