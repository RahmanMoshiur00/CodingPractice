#include<stdio.h>
#include<string.h>

int main()
{
    int n, t;
    scanf("%d", &t);
    for(n=0; n<t; n++){
        char card[21];
        int i, j, Double=0, single=0;

        if(n==0) gets(card);
        gets(card);

        for(i=0, j=0; i<20; i++){
            if(card[i]>='0' && card[i]<='9'){
                card[j] = card[i];
                j++;
            }
        }
        card[j]='\0';

        for(i=14; i>=0; i-=2){
            if(2*(card[i]-'0')>=10){
                Double += 1 + (2*(card[i]-'0'))%10;
            }
            else Double += 2*(card[i]-'0');
        }

        for(i=1; i<16; i+=2) single += (card[i] - '0');

        if((Double+single)%10 == 0) printf("Valid\n");
        else if((Double+single)%10 != 0) printf("Invalid\n");
    }

    return 0;
}
