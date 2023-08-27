#include<stdio.h>
int main()
{
    int t,  l;
    scanf("%d", &t);
    for(l=0; l<t; l++){
        int Ux, Uy, Lx, Ly, r, x, y, i;
        scanf("%d %d %d", &r, &x, &y);
        scanf("%d %d %d %d", &Ux, &Uy, &Lx, &Ly);
        int X[4], Y[4];
        X[0] = r + x; X[1] = x; X[2] = x - r; X[3] = x;
        Y[0] = y; Y[1] = y + r; Y[2] = y; Y[3] = y-r;
        for(i=0; i<4; i++){
            if(!((X[i]>=Ux && X[i]<=Lx) && (Y[i]>=Ly && Y[i]<=Uy))){
                printf("No\n");
                goto end;
            }
        }
        printf("Yes\n");
        end:
            printf("");
    }
}
