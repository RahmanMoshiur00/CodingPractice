#include<bits/stdc++.h>
using namespace std;

int main()
{
    long long n;
    scanf("%lld", &n);
    char str[50], str1[50];
    sprintf(str, "%lld", n);
    int len = strlen(str);
    int i;
    for(i=0; i<len; i++){
        if(i==0){
            if(str[i]=='9'){
                len++;
                str1[i] = '1';
            }
            else{
                str1[i] = str[i] + 1;
            }
        }
        else str1[i] = '0';
    }
    str1[i] = '\0';
    long long m;
    sscanf(str1, "%lld", &m);
    printf("%lld\n", m-n);

    return 0;
}
