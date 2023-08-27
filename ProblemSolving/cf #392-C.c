#include<stdio.h>
int main()
{
    long long test=0, max=0, min=0, sergei=0, row=0, pupil=0, prow=0, ppupil=0;
    scanf("%lld", row);
    scanf("%lld", pupil); scanf("%lld", test); scanf("%lld", prow); scanf("%lld", ppupil);

    long long gun = row * pupil;

    max = gun / test;
printf("Exe1\n");
    if(gun % test == 0) min = max;
    else min = max - 1;
printf("Exe2\n");
    long long again = (row-1) * pupil;
printf("Exe3\n");
    sergei = (again + ppupil) / test;
printf("Exe4\n");
    printf("%lld %lld %lld\n", max, min, sergei);
    return 0;
}
