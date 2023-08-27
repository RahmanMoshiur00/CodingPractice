#include<stdio.h>
#include<string.h>

int main()
{
    char arr[1000];
    int mark[52] = {0};
    int i;
    gets(arr);
    for(i=0; i<strlen(arr); i++){
        if(arr[i]>='a' && arr[i]<='z') mark[arr[i]-'a']++;
        else if(arr[i]>='A' && arr[i]<='Z') mark[arr[i]-'A'+26]++;
    }
    for(i=0; i<26; i++){
        if(mark[i] != 0) printf("%c = %d\n", 'a'+i, mark[i]);
    }
    for(i=26; i<52; i++){
        if(mark[i] != 0) printf("%c = %d\n", 'A'+i-26, mark[i]);
    }
    return 0;
}
