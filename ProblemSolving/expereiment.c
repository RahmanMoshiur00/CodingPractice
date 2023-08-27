#include<stdio.h>
/*nt main()
{
    int a, b, c, d, value;
     value = scanf("%d%d%d", &a, &b, &c);
     printf("valure of scanf=%d", value);
     char c[100];
     scanf("%s", c);
     printf("%s", c);
}*/
int str_len(char array[])
{
    int i, length = 0;
     for(i=0; array[i] != '\0'; i++){
        length++;
     }
     return length;
}

int main()
{
    int len1, len2, len3, i, j;
    char c1[] = {"Puchki"}, c2[] = {"Dambi"};
    len1 = str_len(c1);
    len2 = str_len(c2);
    printf("len1=%d len2=%d\n", len1, len2);
    char c3[len1 + len2];
    for(i=0; i<len1; i++){
        c3[i] = c1[i];
    }
    for(i = 0, j = len1; i < len2; i++, j++) {
        c3[j] = c2[i];
    }
    printf("%s", c3);
}
