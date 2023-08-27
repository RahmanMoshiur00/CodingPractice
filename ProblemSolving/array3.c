#include<stdio.h>
int main()
{
    int a[] = {11, 12, 13, 14, 15, 16, 17, 18, 19};
    int i, j, t;

    for(i=0, j=8; i < 9/2; i++){
        t = a[i];
        printf("t=%d\n", t);
        a[i] = a[j];
        printf("a[%d]=%d\n", i, a[i]);
        a[j] = t;
        printf("a[%d] = %d\n", j, a[j]);
        j--;
    }
    printf("\n");
    for(i=0; i<9; i++) printf("%d\n", a[i]);

}
