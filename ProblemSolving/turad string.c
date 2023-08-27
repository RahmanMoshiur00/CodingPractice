#include <stdio.h>
#include <string.h>

int main()
{
    char a[100], b[100];
    scanf("%s", a);
    scanf("%s", b);

    int sz1 = strlen(a), sz2 = strlen(b), i, j, k;

    if(sz1%sz2!=0){
        printf("No");
        return 0;
    }
    int flag = 1;
    for(i=0; i<sz1; i+=sz2){
        for(j=0, k=i; j<sz2 && k<sz1; j++, k++){
            if(a[k] != b[j]){
                flag = 0;
                break;
            }
        }
        if(flag == 0) break;
    }

    if(flag == 0) printf("No");
    else printf("Yes");

    return 0;
}
