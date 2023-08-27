#include <stdio.h>
#include <string.h>

int main()
{
    char str[100005], s[] = "UUDDLRLRBA";
    scanf("%s", str);



    int n = strlen(str);
    int i, j, flag, ans = 0;

    for(i=0; i+9<n; i++){
        flag = 1;
        for(j=0; j<10; j++){
            if(str[i+j] != s[j]){
                flag = 0;
                break;
            }
        }
        if(flag == 1) ans++;
    }

    printf("%d\n", ans);

    return 0;
}
