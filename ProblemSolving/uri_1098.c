#include<stdio.h>
int main()
{
    double i, j;
    for(i=0.0; i<=2.05; i+=0.2){
            double a = i+3.05;
        for(j=i+1.0; j<=a; j++){
            if(i==0.0 || i==1.0 || i==2.0 || j==3.0 || j==4.0 || j==5.0) printf("I=%.0lf J=%.0lf\n", i, j);
            else printf("I=%.1lf J=%.1lf\n", i, j);
        }
    }
}
