#include<stdio.h>
#include<string.h>
int main()
{
    int t, l;
    scanf("%d", &l);
    for(l=1; l<=t; l++){
        int n, m, k, i;
        scanf("%d %d", &n, &m);
        int arr[n];
        for(i=0; i<n; i++) scanf("%d", &arr[i]);
        for(k=0; k<m; k++){
            char com[10];
            if(k==0) gets(com);
            gets(com);
            if(com[0] == 'S'){
                for(i=0; i<n; i++) arr[i] += atol(com);
            }
            else if(com[0]=='M'){
                for(i=0; i<n; i++) arr[i] *= atol(com);
            }
            else if(com[0]=='D'){
                for(i=0; i<n; i++) arr[i] /= atol(com);
            }
            else if(com[0]=='R'){
                    int j = n;
                for(i=0; i<n/2; i++, j--){
                    int a = arr[i];
                    arr[i] = arr[j];
                    arr[j] = a;
                }
            }
            else if(com[0]=='P'){
                char ind1[n], ind2[n];
                int j=0, q=0, p, zero=0;
                for(i=2; i<n; i++){
                     if(com[i]!=' '){
                        ind1[j] = com[i];
                        j++;
                    }
                    if(com[i]==' '){
                        for(p=i+1; com[p]!='\0'; p++){
                            ind2[q] = com[p];
                            q++;
                        }
                        ind2[q] = '\0';
                        break;
                    }
                }
                ind1[j] = '\0';

                int ab = com[atol(ind1)];
                com[atol(ind1)] = com[atol(ind2)];
                com[atol(ind2)] = ab;
            }
            printf("Case %d:\n", l);
            for(i=0; i<n; i++){
                printf("%d", arr[i]);
                if(i != n-1) printf(" ");
            }
            printf("\n");
        }
    }
}
