#include<stdio.h>
#include<string.h>

main()
{
    int x1, y1, x2, y2, i, t, ind;
    char com[101];

    scanf("%d", &t);

    for(i=1; i<=t; i++){
        scanf("%d %d %d %d %s", &x1, &y1, &x2, &y2, com);
        for(ind=0; ind<strlen(com); ind++){
            if((ind%2==0) && (x1>=0 && x1<=7) && (y1>=0 && y1<=7)){
                if(com[ind]=='L'){
                    x1 = x1 - 1;
                    if(!(x1>=0 && x1<=7)) x1 = x1 + 1;
                }
                else if(com[ind]=='R'){
                    x1 = x1 + 1;
                    if(!(x1>=0 && x1<=7)) x1 = x1 - 1;
                }
                else if(com[ind]=='U'){
                    y1 = y1 + 1;
                    if(!(y1>=0 && y1<=7)) y1 = y1 - 1;
                }
                else if(com[ind]=='D'){
                    y1 = y1 - 1;
                    if(!(y1>=0 && y1<=7)) y1 = y1 + 1;
                }

                if(x1==x2 && y1==y2){
                    printf("Case %d: COLLISION\n", i);
                    break;
                }

            }

            else if((ind%2==1) && (x2>=0 && x2<=7) && (y2>=0 && y2<=7)){
                if(com[ind]=='L'){
                    x2 = x2 - 1;
                    if(!(x2>=0 && x2<=7)) x2 = x2 + 1;
                }
                else if(com[ind]=='R'){
                    x2 = x2 + 1;
                    if(!(x2>=0 && x2<=7)) x2 = x2 - 1;
                }
                else if(com[ind]=='U'){
                    y2 = y2 + 1;
                    if(!(y2>=0 && y2<=7)) y2 = y2 - 1;
                }
                else if(com[ind]=='D'){
                    y2 = y2 - 1;
                    if(!(y2>=0 && y2<=7)) y2 = y2 + 1;
                }

                if(x1==x2 && y1==y2){
                    printf("Case %d: COLLISION\n", i);
                    break;
                }

            }

            if(ind==(strlen(com)-1)){
                printf("Case %d: SAFE\n", i);
                break;
            }
        }
    }
    return 0;
}
