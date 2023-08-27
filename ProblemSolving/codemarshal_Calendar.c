main()
{
    int d, m, y, day;
    while(scanf("%d %d %d", &d, &m, &y)==3){
        day = (d+=m<3?y--:y-2,23*m/9+d+4+y/4-y/100+y/400)%7;
        if(day==0) printf("Sunday\n");
        else if(day==1) printf("Monday\n");
        else if(day==2) printf("Tuesday\n");
        else if(day==3) printf("Wednesday\n");
        else if(day==4) printf("Thursday\n");
        else if(day==5) printf("Friday\n");
        else if(day==6) printf("Saturday\n");
    }

    return 0;
}
