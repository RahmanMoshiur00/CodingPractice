#include<stdio.h>
#include<string.h>

int main()
{
    int n, i, t, space, j, k;
    char ch1, ch2;
    scanf("%d", &t);
    for(i=1; i<=t; i++){
        scanf("%d %c %c", &n, &ch1, &ch2);
        if(ch1=='U'){
            if(ch2=='R'){
                    printf("Case %d:\n", i);
                for(j=1; j<=n; j++){
                    for(k=1; k<=j; k++) printf("*");
                    printf("\n");
                }
            }
            else if(ch2=='L'){
                    printf("Case %d:\n", i);
                for(j=1; j<=n; j++){
                    for(space=n; space>j; space--) printf(" ");
                    for(k=1; k<=j; k++){
                        printf("*");
                    }
                    printf("\n");
                }
            }
        }

        if(ch1=='D'){
            if(ch2=='R'){
                    printf("Case %d:\n", i);
                for(j=n; j>=1; j--){
                    for(k=j; k>=1; k--) printf("*");
                    printf("\n");
                }
            }
            if(ch2=='L'){
                    printf("Case %d:\n", i);
                for(j=n; j>=1; j--){
                    for(space=j; space<n; space++) printf(" ");
                    for(k=j; k>=1; k--){
                        printf("*");
                    }
                    printf("\n");
                }
            }
        }
    }
}
