#include<stdio.h>

int main()
{
    int level, job_num;
    float basic, gross, net;
    printf("Enter level, job number and basic pay\nEnter zero(0) for level to end the program\n");
    scanf("%d %d %f", &level, &job_num, &basic);
    switch(level)
    {
        case 1: gross = (basic + (basic*0.25) + 1500); break;
        case 2: gross = (basic + (basic*0.25) + 950); break;
        case 3: gross = (basic + (basic*0.25) + 600); break;
        case 4: gross = (basic + (basic*0.25) + 250); break;
        case 0: goto end;
        default: printf("Error in level code\n"); goto end;
    }
    if(gross <= 2000) net = gross;
    else if(gross>2000 && gross <= 4000) net = gross - (gross*0.03);
    else if(gross>4000 && gross <= 5000) net = gross - (gross*0.05);
    else if(gross > 6000) net = gross - (gross*0.08);
    printf("%d %d %.2f\n", level, job_num, net);
    end:
    printf("-------End of the program-------\n");
    return 0;
}

