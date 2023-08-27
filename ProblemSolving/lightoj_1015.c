#include<stdio.h>
#include<conio.h>
int main()
{
    int t, j;
    scanf("%d", &t);
    for(j=0; j<t; j++){
        getch();
        //printf("\n");
        int n, i, ans=0;
        scanf("%d", &n);
        for(i=0; i<n; i++){
            int dust;
            scanf("%d", &dust);
            if(dust>0) ans += dust;
        }
        printf("Case %d: %d\n", j+1, ans);
    }
}
