#include<stdio.h>
using namespace std;

bool LeapYear(int y){
    if((y%4==0 && y%100!=0) || y%400==0) return true;
    else return false;
}


int main()
{
    int pYear, pMonth, pDay;
    scanf("%d %d %d", &pYear, &pMonth, &pDay);
    int query;
    int monthDay[13] = {0, 31, 31, 31, 31, 31, 30, 30, 30, 30, 30, 30, 30};
    scanf("%d", &query);
    while(query--){
        int bYear, bMonth, bDay, day=0;
        scanf("%d %d %d", &bYear, &bMonth, &bDay);

        if(LeapYear(bYear)) monthDay[11] = 31;
        else monthDay[11] = 30;

        int mon;
        if(bYear == pYear){
            if(pDay>=bDay) day = pDay - bDay;
            else day = monthDay[bMonth] - bDay + pDay;
            int mon = bMonth + 1;
            while(mon<pMonth) day += monthDay[mon];
        }

        else{
            int mon;
            if(pMonth<=bMonth) mon = 12 - bMonth + pMonth - 1;
            else mon = pMonth - bMonth - 1;
            int start = bMonth + 1;
            if(start>12){
                start %= 12;
                bYear++;
            }
            day = monthDay[bMonth] - bDay + pDay;
            while(mon--){
                day += monthDay[start++];
                if(start>12){
                    start %= 12;
                    bYear++;
                }
            }
        }
        while(bYear<pYear){
            if(LeapYear(bYear)) day += 366;
            else day += 365;
            bYear++;
        }

        printf("%d\n", day);
    }
    return 0;
}
