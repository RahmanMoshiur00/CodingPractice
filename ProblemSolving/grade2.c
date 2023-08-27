#include<stdio.h>

int main()
{
    int y, g;
    printf("Enter marks\n");
    scanf("%d", &y);

    if(y >= 80 && y <= 100){
        printf("Grade is A+");
}

    else if(y >= 70){
        printf("Grade is A");
    }

    else if(y >= 60){
        printf("Grade is A-");
    }

    else if(y >= 50){
        printf("Grade is B");
    }

    else if(y >= 40){
        printf("Grade is C");
    }

    else if(y >= 33 && y <= 39){
        printf("Grade is D");
    }

    else{
        printf("Grade is F");
    }
    return 0;

}
