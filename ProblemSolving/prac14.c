#include<stdio.h>
#include<string.h>

/* //manually finding which string comes first
int main()
{
    char str1[15], str2[15];
    int i, j=0;

    gets(str1);
    gets(str2);

    for(i=0; str1[i]!='\0' || str2[i]!='\0'; i++){
        if(str1[i]>str2[i]){
            printf("'%s' comes first\n", str2);
            goto end;
        }
        else if(str1[i]<str2[i]){
            printf("'%s' comes first\n", str1);
            goto end;
        }
    }

    printf("Strings are equal\n");
    end:
        return 0;
}
*/

//finding which string comes first using library function
int main()
{
    char str1[15], str2[15];
    gets(str1);
    gets(str2);

    if(strcmp(str1, str2)>0) printf("'%s' comes first\n", str2);
    else if(strcmp(str1, str2)<0) printf("'%s' comes first\n", str1);
    else printf("Strings are equal\n");

    return 0;
}
