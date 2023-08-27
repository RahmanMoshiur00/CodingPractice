#include<stdio.h>
#include<math.h>

int main()
{
    int t;
    scanf("%d", &t);
    while(t--){
        int c1, c2, r, x, y;
        scanf("%d %d", &c1, &c2);
        scanf("%d", &r);
        scanf("%d %d", &x, &y);
        if((((x-c1)*(x-c1)) + ((y-c2)*(y-c2)) - (r*r)) >= 0) printf("The point is not inside the circle\n");
        else printf("The point is inside the circle\n");
    }
    return 0;
}
