#include<stdio.h>
int main()
{
    int i, length;
    char c[300];
    gets(c);
    int str_len(char ar[]);
    length = str_len(c);
    printf("Length of %s is %d\n", c, length);

    for(i=0; i<length; i++){
        if(c[i] >= 'a' && c[i] <= 'z'){
            c[i] = 'A' - 'a' + c[i];
        }
    }
    printf("%s", c);

}

int str_len(char array[])
{
    int i, length = 0;
     for(i=0; array[i] != '\0'; i++){
        length++;
     }
     return length;
}

