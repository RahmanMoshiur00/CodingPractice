#include<stdio.h>
#include<string.h>

int main()
{
    int k, i, l;
    char s[1000];
    char m[26][3] = {"a", "b", "c", "d", "e", "f", "g", "h", "i", "j", "k", "l", "m", "n", "o", "p", "q", "r", "s", "t", "u", "v", "w", "x", "y", "z"};

    scanf("%d", &k);
    scanf("%s", s);
    int len = strlen(s) / k;

    int count[26] = {0};
    for (i = 0; i < strlen(s); ++i)
    {
        count[s[i]-'a'] += 1;
    }

    char s1[1000];
    int c = 0;
    for(c = 0; c < 26; ++c)
    {
        if (count[c] % k != 0)
        {
            break;
        }
        else
        {
            for(l=1; l<=( count[c] / k); l++){
                strcat(s1,m[c]);
            }
        }
    }

    if(c == 26)
    {
        int x, y=0;
        for(x=1; x<strlen(s1); x++, y++){
            s[y] = s1[x];
        }
        s[y] = '\0';

        while(k--)
        {

            printf("%s", s);
        }
        printf("\n");
    }
    else
    {
        printf("-1\n");
    }

    return 0;
}
