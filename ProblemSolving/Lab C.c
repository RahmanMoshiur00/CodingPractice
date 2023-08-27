#include<stdio.h>

int check = 1;

int leap_year(int y){
    if(y%400==0 || (y%4==0 && y%100!=0)){
        if(check==1) return 1;
        else return 0;
    }
    else{
        check = 0;
        leap_year(y+1);
    }
}


int main(){
    int y;
    scanf("%d", &y);

    if(leap_year(y)==1){
        printf("%d is a leap year.\n", y);
    }
    else{
        printf("%d is not a leap year.\n", y);
    }

    return 0;
}
