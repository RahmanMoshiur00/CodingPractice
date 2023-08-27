main()
{
    unsigned int i, n, num;
    scanf("%u", &n);
    for(i=1; i<=n; i++){
        scanf("%u", &num);
        if(num>=90 && num<=100) printf("Student %u: A+\n", i);
        else if(num>=80 && num<=89) printf("Student %u: A\n", i);
        else if(num>=70 && num<=79) printf("Student %u: A-\n", i);
        else if(num>=60 && num<=69) printf("Student %u: B+\n", i);
        else if(num>=50 && num<=59) printf("Student %u: B-\n", i);
        else if(num>=40 && num<=49) printf("Student %u: C\n", i);
        else if(num>=35 && num<=39) printf("Student %u: D\n", i);
        else if(num>=0 && num<=34) printf("Student %u: F\n", i);
    }
}
