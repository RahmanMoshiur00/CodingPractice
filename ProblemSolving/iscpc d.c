#include <stdio.h>
#include <string.h>

int main()
{
    char str[105];

    scanf("%s", str);

    int i, len = strlen(str), ans = 0;

    for(i=0; i<len; i++){
        if(str[i] == 'm') ans++;
    }

    int loop = len-1;
    while(loop--){
        scanf("%s", str);
        for(i=0; i<len; i++){
            if(str[i] == 'm') ans++;
        }
    }

    printf("%d\n", ans);

    return 0;
}
