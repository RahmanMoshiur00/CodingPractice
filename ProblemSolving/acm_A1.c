#include<stdio.h>
int main()
{
    int t, l;
    scanf("%d", &t);
    for(l=0; l<t; l++){

        long long num;

        scanf("%lld", &num);

        int i, count=0;

        if(num%2==1){
                printf("First Box\n");
                goto End;
        }
        else if(num%2==0){
            for(i=1; ; i++){
                num = num / 2;
                count++;
                if(num%2==1){
                   break;
                }
            }
        }
        if(count%2==0) printf("First Box\n");
        else if(count%2==1) printf("Second Box\n");
        End:
        printf("");
    }
}
