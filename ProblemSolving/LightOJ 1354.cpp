#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    scanf("%d ", &t);
    for(int l=1; l<=t; l++){
        char dec[40], bin[40];
        gets(dec);
        gets(bin);
        int d[4];
        char b[4][10];
        sscanf(dec, "%d.%d.%d.%d", &d[0], &d[1], &d[2], &d[3]);

        int len = strlen(bin);

        for(int j=0, i=0, k=0; j<len; j++){
            if(bin[j]=='.'){
                b[i][k] = '\0';
                k=0;
                i++;
                continue;
            }
            b[i][k++] = bin[j];
        }
        b[3][8] = '\0';

        int convert[4];

        for(int i=0; i<4; i++){
            convert[i] = 0;
            for(int j=7, k=0; j>=0; j--, k++){
                    int m = b[i][j] - '0';
                convert[i] += m * ((int) pow(2, k));
            }
        }

        int mark = 1;
        for(int i=0; i<4; i++){
            if(convert[i]!=d[i]){
                mark = 0;
                break;
            }
        }
        if(mark==1) printf("Case %d: Yes\n", l);
        else printf("Case %d: No\n", l);
    }

    return 0;
}
