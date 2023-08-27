#include<stdio.h>
#include<string.h>

int main()
{
    int i, count=0;
    char num[20];
    scanf("%s", num);

    for(i=0; i<strlen(num); i++){
        if(num[0] == '-') goto end;
        else{
            if(num[i]=='4' || num[i]=='7') count++;
        }
    }

    if(count==4 || count==7) printf("YES\n");
    else printf("NO\n");

    end:
    return 0;
}

