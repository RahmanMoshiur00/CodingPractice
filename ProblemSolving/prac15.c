#include<stdio.h>
#include<string.h>
#include<stdlib.h>

//using scanf
/*
int main()
{
    int d, m, y;
    scanf("%d/%d/%d", &d, &m, &y);
    printf("%d %d %d\n", d, m, y);
}
*/


//using string conversion
int main()
{
    char date[15], d[3], m[3], y[5];
    gets(date);

    int i, count=0, j=0, k=0, l=0;

    for(i=0; i<strlen(date); i++){
        if(date[i]>='0' && date[i]<='9'){
            if(count==0){
                d[j++] = date[i];
            }
            else if(count==1) m[k++] = date[i];
            else y[l++] = date[i];
        }
        if(date[i]=='/') count++;
    }

    int da, mo, ye;
    da = atoi(d);
    mo = atoi(m);
    ye = atoi(y);

    printf("%d %d %d\n", da, mo, ye);


    return 0;
}
