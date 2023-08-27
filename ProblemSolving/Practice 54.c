#include<stdio.h>
int main()
{
    int t, l;
    scanf("%d", &t);
    for(l=1; l<=t; l++){
        int first[3], sec[3], i, ans=0;
        scanf("%d %d %d %d %d %d", &first[0], &first[1], &first[2], &sec[0], &sec[1], &sec[2]);
        for(i=0; i<3; i++){
            if(first[i]<sec[i]){
                ans = 1;
                break;
            }
            else if(first[i]>sec[i]){
                ans = 2;
                break;
            }
        }
        if(ans==0) printf("Tie\n");
        else if(ans==1) printf("Player1\n");
        else if(ans==2) printf("Player2\n");
    }
    return 0;
}
