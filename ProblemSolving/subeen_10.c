#include<stdio.h>
int main()
{
    int t;
    scanf("%d", &t);
    while(t--){
        int op, bat, ball;
        scanf("%d %d %d", &op, &bat, &ball);
        printf("%.2lf %.2lf\n", (double)bat/(double)((300-ball)/6.0), (double)(op-bat+1)/(double)(ball/6.0));
    }
    return 0;
}
