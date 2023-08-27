#include<stdio.h>
int main()
{
    int i, count=0;
     double n, sum = 0.00;
     for(i=0; i<6; i++){
         scanf("%lf", &n);
         if(n>=0.0){
             count++;
             sum += n;
         }
     }
     printf("%d valores positivos\n", count);
     printf("%.1lf\n", sum/count);
}
