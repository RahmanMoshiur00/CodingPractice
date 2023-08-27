#include<stdio.h>
int main()
{
    int col, i, j;
    scanf("%d", &col);
    char com;
    scanf("%c", &com);
    double arr[12][12], sum=0.0;
    for(i=0; i<12; i++){
        for(j=0; j<12; j++){
            scanf("%lf", &arr[i][j]);
            printf("");
            if(j==col) sum += arr[i][j];
        }
    }
    if(com=='S') printf("%.1lf\n", sum);
    else printf("%.1lf\n", sum/12.0);
}
