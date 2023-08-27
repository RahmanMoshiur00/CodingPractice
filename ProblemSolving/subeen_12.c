#include<stdio.h>
int main()
{
    int t;
    scanf("%d", &t);
    while(t--){
        int n, count=0, i;
        scanf("%d", &n);
        for(i=1; i*5<=n; i++){
            count++;
            if(i%5==0){
                int a = i;
                while(a%5==0){
                    count++;
                    a = a / 5;
                }
            }
        }
        printf("%d\n", count);
    }
    return 0;
}
