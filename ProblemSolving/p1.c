#include<stdio.h>
#include<math.h>
#include<string.h>
int main()
{
    int i, fact=1;
	for(i=2;i<=100;i++)
	{
		fact *= i;
		fact %= 97;

	}
	printf("%d\n",fact);
}
