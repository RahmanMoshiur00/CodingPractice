#include <stdio.h>

int main ()
{
    int giants;
    scanf("%d", &giants);

    int i, j, flag;
    char str[10];

    for(i=1; i<=giants; i++)
    {
        scanf("%s", str);
        flag = 0;
        for(j=0; str[j]!='\0'; j++)
        {
            if(str[j]=='a' || str[j]=='e' || str[j]=='i' || str[j]=='o')
            {
                flag = 1;
            }
        }
        if(flag == 0)
        {
            printf("No\n");
        }
        else
        {
            printf("Yes\n");
        }
    }

    return 0;
}
