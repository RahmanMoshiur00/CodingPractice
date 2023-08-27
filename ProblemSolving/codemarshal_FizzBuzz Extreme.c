#include<stdio.h>
#include<string.h>

main()
{

    int t, i;
    scanf("%d", &t);
    for(i=1; i<=t; i++){
        long long int sum=0, j;
        char num[100001];
        if(i==1) gets(num);
        gets(num);
        for(j=0; j<strlen(num); j++){
            if(num[j]>='0' && num<='9') sum += num[j] - '0';
        }
        int last = num[(strlen(num))-1] - '0';
        if(sum%3==0 && !(last==0 || last==5)) printf("Case %d: Fizz\n", i);
        else if(sum%3!=0 && (last==0 || last==5)) printf("Case %d: Buzz\n", i);
        else if(sum%3==0 && (last==0 || last==5)) printf("Case %d: FizzBuzz\n", i);
        else if(sum%3!=0 && !(last==0 || last==5)) printf("Case %d: Null\n", i);
    }
}
