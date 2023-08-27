#include<stdio.h>
int main()
{
    int array[] = {11, 12, 13, 14, 15, 16, 17, 18, 19, 20}, array2[10];
    /*onno array na niye ekoi array te reverse content gula rakha jacche na kewno?*/
    int i, j, k;
    for(i=9,j=0; i>=0; i--, j++){
        array2[j] = array[i]; /*ekhane onno arekti array te value gula assign korle reverse value thik thaktese*/
        }
    for(i=0; i<10; i++){
    printf("%d\n", array2[i]);
    }
}
/*20 to 16 print6 korar por abar keno 16to20 print kortese?jekhane 15to11 output deyar kotha?jodi code/ loop thik na thake tahole 20to16 print korlo keno?*/
