#include<stdio.h>
int main()
{
    int t, l;
    scanf("%d", &t);
    for(l=0; l<t; l++){
        int univ, i, j;
        scanf("%d", &univ);
        int teamuni[univ];
        for(i=0; i<univ; i++){
            scanf("%d", &teamuni[i]);
        }
        int max = teamuni[0];
        for(i=1; i<univ; i++){
            if(teamuni[i]>max) max = teamuni[i];
        }
        int min = teamuni[0];
        for(i=1; i<univ; i++){
            if(teamuni[i]<min) min = teamuni[i];
        }
        int res = 0, count=0, a;
        for (i = 0; i < univ; ++i) {
            for (j = i + 1; j < univ; ++j) {
                 if (teamuni[i] > teamuni[j]){
                    a = teamuni[i];
                    teamuni[i] = teamuni[j];
                    teamuni[j] = a;
                }
            }
        }

        /*for(i=0; i<univ; i++){
            for(j=0; j<univ; j++){
                if(teamuni[j]%teamuni[i]==0){
                    count++;
                    if(count==univ) res = teamuni[i];
                }
                else if(teamuni[j]%teamuni[i] != 0){
                    count=0;
                    break;
                }
            }
        }*/
        count==0;
        if(res==0){
            for(i=2; i<=teamuni[0]; i++){
                for(j=0; j<univ; j++){
                    if(teamuni[j]%i==0){
                    count++;
                    if(count==univ) res = i;
                }
                else if(teamuni[j]%i != 0){
                    count=0;
                    break;
                }
                }
            }
        }
        if(res==0) res = 1;
        long long sum = 0;
        for(i=0; i<univ; i++) sum += teamuni[i];
        printf("%d %d\n", res, (int)sum/res);
    }
}
