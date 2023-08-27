#include<stdio.h>
#include<string.h>
int cPal(char str[], int len, int left, int right){
    char rev[len-left-right];
    int i, k;
    for(i=(strlen(str)-1-right), k=0; i>=(0+left); i--, k++) rev[k] = str[i];
    rev[k] = '\0';
    for(i=(0+left), k=0; i<=(strlen(str)-1-right); i++, k++){
        if(rev[k] != str[i]) return 0;
    }
    return (strlen(rev));
}
int main()
{
    int t, l;
    scanf("%d", &t);
    for(l=1; l<=t; l++){
        char str[1001];
        int right, left, ans=1;
        scanf("%s", str);
        for(left=0; left<strlen(str); left++){
            for(right=0; right<=strlen(str); right++){
                if(cPal(str, strlen(str), left, right) != 0){
                    if(cPal(str, strlen(str), left, right)>ans) ans = cPal(str, strlen(str), left, right);
                    break;
                }
            }
        }

        for(right=0; right<=strlen(str); right++){
            for(left=0; left<strlen(str); left++){
                if(cPal(str, strlen(str), left, right) != 0){
                    if(cPal(str, strlen(str), left, right)>ans) ans = cPal(str, strlen(str), left, right);
                    break;
                }
            }
        }

        printf("Case %d: %d\n", l, ans);
    }
    return 0;
}
