#include<stdio.h>
#include<string.h>

long long fact( int num ){
    int count = 1, i;
    for(i=2; i<=num; i++) count *= i;
    return count;
}

int main()
{
    int t, l;
    scanf("%d", &t);
    for(l=0; l<t; l++) {
        char arr[1000];
        char str[10][21];

        if(l==0) gets(arr);
        gets(arr);

        int i, k=0, j=0, n=0;

        for(i=0; i<strlen(arr); i++){
            if((arr[i]>='a' && arr[i]<='z') || (arr[i]>='A' && arr[i]<='Z') || (arr[i]>='0' && arr[i]<='9')){
                str[k][j] = arr[i];
                j++;
            }
            if(arr[i+1]==' ' || arr[i+1]=='\0'){
                str[k][j] = '\0';
                k++;
                n++;
                j = 0;
            }
        }
        int count, mark[10];
        k = 0;
        char ch = '!';
        for(i=0; i<n; i++){
            count = 1;
            for(j=i+1; j<n; j++){
                if(strcmp(str[i], str[j])==0){
                    count++;
                    str[j][0] = ch++;
                }
            }
            if(count>1) mark[k++] = count;
        }

        long long ans = 1;
        for(i=0; i<k; i++){
            ans *= fact(mark[i]);
        }

        printf("1/%d\n", fact(n)/ans);

    }
    return 0;
}
