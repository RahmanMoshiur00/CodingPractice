#include <stdio.h>

int main()
{
    int m;

    scanf("%d", &m);

    if(m >= 80 && m <= 100){
        printf("The grade is A+");
    }
    else if(m >= 70 && m <= 79){
        printf("The grade is A");
    }
    else if(m >= 60 && m <= 69){
        printf("The grade is A-");
    }
    else if(m >= 50 && m <= 59){
        printf("The grade is B");
    }
    else if(m >= 40 && m <= 49){
        printf("The grade is C");
    }
    else{
        printf("grade is F");
    }
    return 0;
}
