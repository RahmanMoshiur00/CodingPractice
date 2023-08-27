#include <stdio.h>

int main()
{
    int m;
    printf("Enter number\n");
    scanf("%d", &m);

    if(m >=80 && m <= 100){
        printf("Grade is A+\n");
    }

    else if(m >= 75 && m <= 79){
        printf("Grade is A\n");
    }

    else if(m >= 70 && m <= 74){
        printf("Grade is A-\n");
    }

    else if(m >=65 && m <= 69){
        printf("Grade is B+\n");
    }

    else if(m >= 60 && m <= 64){
        printf("Grade is B\n");
    }

    else if(m >=55 && m <= 59){
        printf("Grade is B-\n");
    }

    else if(m >=50 && m <= 54){
        printf("Grade is C\n");
    }

    else if(m >= 45 && m <= 49){
        printf("Grade is D\n");
    }

    else{
        printf("Grade is F\n");
    }
        return 0;
}
