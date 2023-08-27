#include<stdio.h>
#include<stdlib.h>

int checkLeapYear(int year)
{
	if((year%4==0 && year%100!=0) || year%400==0)
		return 1;
	else
		return 0;
}
void displayCalender(int day,int year,int leapYear)
{
int  daysMonth, dayCounter, month;
     printf("\n             %d\n\n\n", year);
     for (month=1; month<=12; month++){
          switch(month)
		  {
		  case 1:
			  printf("            January"); //printing spaces for better view of the output
              daysMonth = 31;
              break;
		  case 2:
			  printf("\n\n\n            February");
			  daysMonth = leapYear ? 29 : 28;
			  break;
		  case 3:
			  printf("\n\n\n            March");
			  daysMonth = 31;
			  break;
		  case 4:
			  printf("\n\n\n            April");
			  daysMonth = 30;
              break;
          case 5:
              printf("\n\n\n            May");
              daysMonth = 31;
              break;
          case 6:
			  printf("\n\n\n            June");
              daysMonth = 30;
              break;
          case 7:
			  printf("\n\n\n            July");
              daysMonth = 31;
              break;
          case 8:
			  printf("\n\n\n            August");
              daysMonth = 31;
              break;
          case 9:
			  printf("\n\n\n            September");
              daysMonth = 30;
              break;
          case 10:
			  printf("\n\n\n            October");
              daysMonth = 31;
              break;
          case 11:
			  printf("\n\n\n            November");
              daysMonth = 30;
              break;
          case 12:
			  printf("\n\n\n            December");
              daysMonth = 31;
              break;
		  }

		  printf("\n\nSun  Mon  Tue  Wed  Thu  Fri  Sat\n");

		  for(dayCounter = 1; dayCounter<= 1 + day * 5; dayCounter++) printf(" ");

		  for(dayCounter = 1; dayCounter <= daysMonth; dayCounter++)
		  {
			  printf("%2d", dayCounter);

			  if((dayCounter + day) % 7 > 0)
				  printf("   ");
			  else
				  printf("\n ");
		 }

		  day = (day + daysMonth) % 7;
	 }
}

int main()
{
	int day, year, leapYear;
	int x, y, z;

	printf("Please Input Year Name:");

	scanf("%d",&year);

	x = (year-1)/4;
	y = (year-1)/100;
	z = (year-1)/400;

	day = (year+x-y+z)%7;

	leapYear = checkLeapYear(year);

	displayCalender(day, year, leapYear);

}

