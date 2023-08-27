#include<stdio.h>
#include<string.h>
int main()
{
    int t, l;
    scanf("%d", &t);
    for(l=0; l<t; l++){
        char arr[1001], vow[1001], con[1001];
        char vowel[] = "AEIOUaeiou";
        if(l==0) gets(arr);
        gets(arr);
        int i, j, k=0, m=0;
        for(i=0; i<strlen(arr); i++){
            int check=0;
            for(j=0; j<strlen(vowel); j++){
                if(arr[i]==vowel[j]){
                    vow[k++] = arr[i];
                    check=1;
                    break;
                }
                if(arr[i]==' ') check=1;
            }
            if(check==0) con[m++] = arr[i];
        }

        vow[k] = 0;
        con[m] = 0;
        printf("%s\n%s\n", vow, con);
    }
    return 0;
}
