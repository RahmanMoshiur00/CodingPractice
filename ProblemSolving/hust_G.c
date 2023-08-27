#include<stdlib.h>

main()
{
    int test, i, lift_floor, ground_floor = 0, my_floor;
    scanf("%d", &test);

    for(i=1; i<=test; i++){
        scanf("%d %d", &my_floor, &lift_floor);
        printf("Case %d: %d\n", i, (4 * abs(lift_floor - my_floor)) + 19 + (4 * abs(my_floor - ground_floor)));
    }
}
