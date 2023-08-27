#include<stdio.h>
#include<string.h>
int main()
{
    int t, l;
    scanf("%d", &t);
    for(l=0; l<t; l++){
        char str1[100001], str2[100001];
        scanf("%s", str1);
        scanf("%s", str2);
        unsigned long long res = 0;
        int temp=0, i, j;
        for(i=0; i<strlen(str1); i++){
                temp = 0;
            for(j=0; j<strlen(str2); j++){
                if(str1[i]==str2[j]){
                    str2[j] = '0';
                    temp = 1;
                }
            }
            if(temp==0) res += 2;
        }
        printf("%llu\n", res+(strlen(str2)-strlen(str1)));
    }
}
