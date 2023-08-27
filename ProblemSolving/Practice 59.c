#include<stdio.h>
#include<conio.h>
int d1,d2,d3,m1,m2,m3,y1,y2,y3;
void year(int d1,int m1,int y1,int d2,int m2,int y2);
void main()
{
clrscr();
printf("please enter the current date \n");
printf("enter the day");
scanf("%d",&d1);
printf("enter the month");
scanf("%d",&m1);
printf("enter the year");
scanf("%d",&y1);
printf("Now thank you for your cooperation \n now please enter the date of birth");
printf("enter the day");
scanf("%d",&d2);
printf("enter the month");
scanf("%d",&m2);
printf("enter the year");
scanf("%d",&y2);
year(d1,m1,y1,d2,m2,y2);
getch();
}

void year(int d1,int m1,int y1,int d2,int m2,int y2)
{
    if(d2>d1)
    {
    m1=m1-1;
    d1=d1+30;
    }
    if(m2>m1)
    {
    y1=y1-1;
    m1=m1+12;
    }
    if(y2>y1)
    {
    exit(0);
    }
    d3=d1-d2;
    m3=m1-m2;
    y3=y1-y2;
    printf("current age is \n day %d \n month %d \n year %d ",d3,m3,y3);


}
