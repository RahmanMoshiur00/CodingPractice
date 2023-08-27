#include<stdio.h>
int main()
{
    int t, l;
    scanf("%d", &t);
    for(l=1; l<=t; l++){
        int i, j, k, x, y, z;
        scanf("%d %d %d %d %d %d", &i, &j, &k, &x, &y, &z);
        if((i<x && j<y && k<z) || (i<x && k<y && j<z) || (j<x && i<y && k<z) || (j<x && k<y && i<z) || (k<x && i<y && j<z) || (k<x && j<y && i<z)) printf("Case %d: 1st box fits into 2nd box\n", l);
        else if((x<i && y<j && z<k) || (x<i && y<k && z<j) || (x<j && y<i && z<k) || (x<j && y<k && z<i) || (x<k && i>y && j>z) || (k>x && j>y && i>z)) printf("Case %d: 2nd box fits into 1st box\n", l);
        else printf("Case %d: Does not fit in any order\n", l);
    }
    return 0;
}
