#include<stdio.h>

int main()
{
    double m[2][5];
    int c, r;


    for(c = 0; c <= 1; c++){
        for(r = 0; r <= 4; r++){
            scanf("%lf", &m[c][r]);
        }
    }

    for(c = 0; c <= 1; c++){
        for(r = 0; r <=4; r++){
            printf("Class:%d, Roll:%d ,Marks: %.2lf\n", c+6, r+1, m[c][r]);
        }
    }

    return 0;

}
