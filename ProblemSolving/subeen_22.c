#include<stdio.h>
#include<math.h>
int main()
{
    int t;
    scanf("%d", &t);
    while(t--){
        int a, b, count=0, i, j;
        scanf("%d %d", &a, &b);
        for(i=a; i<=b; i++){
                int chk = 0;
            for(j=2; j<=sqrt(i); j++){
                if(i%j==0){
                    chk=1;
                    break;
                }
            }
            if(chk==0) count++;
        }
        if(a==1) count--;
        printf("%d\n", count);
    }
    return 0;
}
