#include<stdio.h>
#include<math.h>
int main()
{
    int t, l;
    scanf("%d", &t);
    for(l=0; l<t; l++){
        int n;
        scanf("%d", &n);
        int i;
        for(i=2; i<=(int)sqrt(n*1.0); i++){
            if(n%i==0){
                printf("%d nao eh primo\n", n);
                goto last;
            }
        }
        printf("%d eh primo\n", n);
        last:
            printf("");
    }
}
