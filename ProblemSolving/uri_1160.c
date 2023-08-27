#include<stdio.h>
#include<stdlib.h>
int main()
{
    int t;
    scanf("%d", &t);
    while(t--){
        int a, b , count=1;
        double ga, gb, pa, pb, ans;
        scanf("%d %d %lf %lf", &a, &b, &ga, &gb);
        pa = (double)a;
        pb = (double)b;

        if(gb==0.0){
            printf("%.0lf anos.\n", 1.0+ceil(((b-a)*1.0)/ga));
        }

        else
            while(1){
                ans = (pb + (pb*(gb/100.0))) - (pa + (pa*(ga/100.0)));
                pa += pa*(ga/100.0);
                pb += pb*(gb/100.0);
                if(ans>=0.0) count++;
                if(count>100){
                    printf("Mais de 1 seculo.\n");
                    break;
                }
                else if(ans<0.0){
                    printf("%d anos.\n", count);
                    break;
                }
            }
    }
}
