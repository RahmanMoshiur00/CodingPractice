#include<stdio.h>
#include<math.h>
int main()
{
    int t, i, star;
    float r;
    for(t=0; t<11; t++) printf("-----");
    printf("\n");
    for(t=0; t<=3000; t += 150){
        r = exp((-0.001) * t);
        star = (int)(r * 50);
        printf("|");
        for(i=0; i<star; i++) printf("*");
        printf("#\n");
    }

}
