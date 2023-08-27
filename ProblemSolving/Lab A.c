#include<stdio.h>

int second_to_minute(int s){
    return s/60;
}

int second_to_day(int s){
    return s/(3600*24);
}

int minute_to_second(int m){
    return m*60;
}

int minute_to_day(int m){
    return m/(60*24);
}

int day_to_month(int d){
    return d/30;
}

int day_to_year(int d){
    return d/365;
}

int month_to_day(int m){
    return m*30;
}

int month_to_year(int m){
    return m/12;
}

int year_to_day(int y){
    return y*365;
}

int year_to_month(int y){
    return y*12;
}


int main()
{
    printf("Enter how many times you want to have conversion: ");
    int i, n, sec, min, day, mon, year;
    scanf("%d", &n);
    printf("Enter second, minute, day, month and year respectively separating by space:\n");
    for(i=0; i<n; i++){
        scanf("%d %d %d %d %d", &sec, &min, &day, &mon, &year);
        printf("%d second(s) = %d minute(s) and %d second(s)\n", sec, second_to_minute(sec), sec%60);
        printf("%d second(s) = %d day(s) and %d second(s)\n", sec, second_to_day(sec), sec%(3600*24));
        printf("%d minute(s) = %d seconds(s)\n", min, minute_to_second(sec));
        printf("%d minute(s) = %d day(s) and %d minute(s)\n", min, minute_to_day(min), min%(60*24));
        printf("%d day(s) = %d month(s) and %d day(s)\n", day, day_to_month(day), day%30);
        printf("%d day(s) = %d year(s) and %d day(s)\n", day, day_to_year(day), day%365);
        printf("%d month(s) = %d days\n", mon, mon*30);
        printf("%d month(s) = %d year(s) and %d month(s)\n", mon, month_to_year(mon), mon%12);
        printf("%d year(s) = %d days\n", year, year*365);
        printf("%d year(s) = %d months\n", year, year_to_month(year));
    }

    return 0;
}
