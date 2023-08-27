#include<stdio.h>

int main()
{
    char str[20];
    int ct,t,index,digitsum,numsum,k,i,num;
    ct=1;
    scanf("%d", &t);
    while(ct<=t)
    {
        index=0;
        digitsum=0;
        numsum=0;
        if(ct==1) gets(str);
        gets(str);
        for(i=0;str[i]!= '\0';i++)
        {
            if(str[i]!=' ')
            {
                str[index]=str[i];
                index++;
            }
        }
        str[index] = '\0';
        for(i=0; i<16; i=i+2)
        {
            num =(str[i]-48)*2;
            for(k=0;num!=0;num=num/10){
                digitsum = digitsum + (num%10);
            }
        }
        for(k=1;k<16;k=k+2)
        {
            numsum = numsum + str[k]-48;
        }
        if((digitsum+numsum)%10==0)printf("Valid\n");
        else printf("Invalid\n");
        ct++;

    }
    return 0;
}
