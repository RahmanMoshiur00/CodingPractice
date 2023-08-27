#include<stdio.h>
int main()
{
    int n[3], n1[3], i, j;
    for(i=0; i<3; i++) scanf("%d", &n[i]);
    for(i=0; i<3; i++) n1[i] = n[i];
    for(i=0; i<3; i++){
        for(j=i+1; j<3; j++){
            if(n[i]>n[j]){
                int a = n[i];
                n[i] = n[j];
                n[j] = a;
            }
        }
    }
    for(i=0; i<3; i++) printf("%d\n", n[i]);
    printf("\n");
    for(i=0; i<3; i++) printf("%d\n", n1[i]);
}
