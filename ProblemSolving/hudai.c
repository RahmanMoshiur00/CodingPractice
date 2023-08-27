#include <stdio.h>


int main()
{
    int T;
    scanf("%d ", &T);

    char ch[2];

    while (T--)
    {
        scanf("%s", ch);

        if (ch[0] >= 'a' && ch[0] <= 'z')
            printf("Lowercase Character\n");

        else if (ch[0] >= 'A' && ch[0] <= 'Z')
            printf("Uppercase Character\n");

        else if (ch[0] >= '0' && ch[0] <= '9')
            printf("Numerical Digit\n");

        else
            printf("Special Character\n");
    }

    return 0;
}
