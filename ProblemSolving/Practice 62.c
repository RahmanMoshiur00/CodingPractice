#include<stdio.h>

int main()
{
    int n , i, pd, pm, py, bd, bm, by, d, m, y;

    for(i = 0; i <= scanf("%d", &n); i++)
    {
    printf("Enter present 'day,month and year' pressing 'enter' button:\n");
    scanf("%d\n%d\n%d", &pd, &pm, &py);

    printf("Enter birth date:'day,month,year' pressing 'enter' button\n");
    scanf("%d\n%d\n%d", &bd, &bm, &by);

    if(pd > bd){
    d = pd - bd;
    printf("day: %d\t", d);
    }
        else{
            d = ( pd + 30 ) - bd;
            bm = bm + 1;
            printf("day: %d\t", m);
            }
    if( pm > bm ){
        m = pm - bm;
        printf("month: %d\t", m);
        }
        else{
            m = ( pm + 12 ) - bm;
            by = by + 1;
            printf("month: %d\t", m);
        }

    y = py - by;
    printf("year: %d\n\n", y);
    }

    return 0;
}
