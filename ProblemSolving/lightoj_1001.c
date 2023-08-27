#include<stdio.h>

main()
{
    int t,j;
    scanf("%d", &t);
    for(j=0; j<t; j++){
        int n[t];
        scanf("%d", &n[j]);
        int a=0, b = n[j];
        if(j==0) printf("%d %d\n", a, b);
        else{
            int i;
            for(i=0; i<j; i++){
                if(n[i]==n[j]){
                    a++;
                    b--;
                }
            }
            printf("%d %d\n", a, b);
        }
    }
}
