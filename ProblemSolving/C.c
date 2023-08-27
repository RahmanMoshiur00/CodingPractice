#include<stdio.h>
int main()
{
    int row;
    printf("enter row number: ");
    scanf("%d", &row);

    for(int i=1; i<=row;i++)
    {
        for(int s=1; s<=(row-i);s++)
        {
            printf(" ");
        }

        for(int k=i; k<=((2*(i-1))+1); k++)
        {
            printf("%d ",k);
        }

        for(int k=((2*(i-1)));k>=i;k--)
            {
                printf("%d ",k);
            }
            printf("\n");
    }
}
