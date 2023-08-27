#include<stdio.h>

int main()
{
    int i, n, bowl, plate, dish, wash = 0, bowl1, plate1;
    scanf("%d %d %d", &n, &bowl, &plate);

    bowl1 = bowl;
    plate1 = plate;

    for(i=0; i<n; i++){
        scanf("%d", &dish);
        if(dish == 1){
            if(bowl >= plate){
                bowl1 = bowl1 - 1;
                if(bowl1 < 0) wash++;
            }
            else if(bowl<plate){
                plate1 = plate1 - 1;
                if(plate1 < 0) wash++;
            }
        }

        else if(dish == 2){
            if(bowl1 > 0) bowl1 = bowl1 - 1;
            else{
                plate1 = plate1 - 1;
                if(plate1 < 0) wash++;
            }
        }
    }

    printf("%d\n", wash);
}
