#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main()
{
    int t, n;

    scanf("%d", &t);
    for(n=0; n<t; n++){
            char cnum[429496729];
            int i, j, ad;
            if(n==0) scanf("%s", cnum);
        scanf("%s", cnum);
        for(ad=1; ad<=1000; ad++){
            long inum = atol(cnum);
            for(i=0, j=strlen(cnum)-1; i<strlen(cnum)/2; i++, j--){
                int temp = cnum[i];
                cnum[i] = cnum[j];
                cnum[j] = temp;
            }
            long inumrev = atol(cnum);
            long add = inum + inumrev;
            if(add==9339){printf("RESULT\n"); break;}

        }

    }


}
