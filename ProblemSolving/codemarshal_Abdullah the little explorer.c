#include<stdio.h>
#include<string.h>

int main()
{
    int t, i;
    scanf("%d", &t);
    for(i=1; i<=t; i++){
        char path[20001];
        int j, k, x, y;
        scanf("%d %d", &x, &y);
        scanf("%s", path);
        for(j=0; j<strlen(path)-1; j++){
            int n;
            if(j%2==0 && path[j]=='E'){
                n = path[j+1] - '0';
                x += n;
            }
            else if(j%2==0 && path[j]=='N'){
                n = path[j+1] - '0';
                y += n;
            }
            else if(j%2==0 && path[j]=='W'){
                n = path[j+1] - '0';
                x -= n;
            }
            else if(j%2==0 && path[j]=='S'){
                n = path[j+1] - '0';
                y -= n;
            }
        }
        printf("%d %d\n", x, y);
    }
    return 0;
}
