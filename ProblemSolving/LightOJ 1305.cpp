#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    scanf("%d", &t);
    for(int l=1; l<=t; l++){
        int Ax, Ay, Bx, By, Cx, Cy, Dx, Dy;
        scanf("%d %d %d %d %d %d", &Ax, &Ay, &Bx, &By, &Cx, &Cy);
        Dx = (Cx - Bx) + Ax;
        Dy = (Ay - By) + Cy;
        int area = 0;
        area = (Ax*By) + (Bx*Cy) + (Cx*Dy) + (Dx*Ay) - (Ay*Bx) - (By*Cx) - (Cy*Dx) - (Dy*Ax);
        printf("Case %d: %d %d %d\n", l, Dx, Dy, abs(area/2));
    }
    return 0;
}
