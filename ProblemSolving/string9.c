#include<stdio.h>
#include<string.h>
//int compare(char a[], char b[])
int main()
{
    int i;
    char a[10], b[10], c[10];
    gets(a);
    gets(b);
    int m = strlen(a), n = strlen(b);
    for(i=0; i<10; i++){

        if(a[i] > b[i]){
            printf("'%s' comes first before '%s\n'", b, a);
            break;
        }
        else if(a[i] < b[i]){
            printf("'%s' comes first before '%s'\n", a, b);
            break;
        }
        else if(n==m && a[i]==b[i]){
            printf("'%s' and '%s' are equal\n", a, b);
            ;
        }


        /*if(a[i] == b[i]){
            printf("strings are equal\n");
        }*/
        //if(a[i] == b[i] && strlen(a) == strlen(b)) return 0;
    }
}

/*int main()
{
    char a[1000], b[1000];
    gets(a);
    gets(b);
    int n = compare(a, b);
    if(n == 1) printf("'%s' comes first before '%s'", b, a);
    else if(n == -1) printf("'%s' comes first before '%s'", a, b);
    else if(n == 0){
        printf("strings are equal");
    }

}*/
