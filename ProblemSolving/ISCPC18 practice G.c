#include<stdio.h>
#include<math.h>

int main()
{
    int t, tc;
    scanf("%d", &tc);

    for(t = 1; t<=tc; t++){
        int x, y;
        scanf("%d %d", &x, &y);

        if(x<=5){
            printf("Yes! The ant is Alive.\n", t);
        }
        else{
            printf("Sorry !the ant is nomore.\n", t);
        }
    }

}

