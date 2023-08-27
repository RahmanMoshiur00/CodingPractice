#include<stdio.h>
int main()
{
    double line[3];
    int i;
    for(i=0; i<3; i++) scanf("%lf", &line[i]);
    double max = line[0];
    int max_ind = 0;
    for(i=1; i<3; i++){
        if(line[i]>max){
            max = line[i];
            max_ind = i;
        }
    }
    double sum = 0.0;
    for(i=0; i<3; i++){
        if(i!=max_ind) sum += line[i];
    }
    if(sum>max) printf("Perimetro = %.1lf\n", line[0]+line[1]+line[2]);
    else{
        printf("Area = %.1lf\n", ((line[0]+line[1])*line[2])/2.0);
    }

}
