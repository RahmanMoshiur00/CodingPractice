/*51*/
#include<stdio.h>
#include<string.h>
int main()
{
    char str[30];
    printf("Enter a string:");
    gets(str);
    int i, count = 0, len = strlen(str);
    for(i=0; i<len; i++){
        if(str[i]=='a' || str[i]=='e' || str[i]=='i' || str[i]=='o' || str[i]=='u' || str[i]=='A' || str[i]=='E' || str[i]=='I' || str[i]=='O' || str[i]=='U' ) count ++;
    }
    printf("there are %d vowels in %s", count, str);
}
