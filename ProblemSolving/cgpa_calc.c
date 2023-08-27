#include<stdio.h>

int main()
{
    int m;
    read:

    printf("Enter 1 for calculating CGPA of University,\n2 for calculating GPA of School and\n3 for calculating GPA of college: ");
    scanf("%d", &m);


/*Starting to calculate CGPA of an UNIVERSITY student; where grade range and highest mark are not fixed and user needs to fix the range.
Because, different university have different grade ranges and highest marks!
For example, in HSTU "80%-100% marks = grade point 4.0" and highest mark is 150; but in BRAC University "80%-84% marks = grade point 3.5" and highest mark is 100!*/
    if(m==1){
        int course, i, n, count = 0, highestNumber;
        float sum = 0.0, count1 = 0.0, credit[20], mark[20], higherValue[30], lowerValue[30], gradePoint[30], grade[20];

        printf("\n\n\nInput grading range like '75 79 4'\nMust enter lower mark in first, then higher and then grade; otherwise program will produce garbage!\n'75 79 4' means that 'grade point is 4 from 75%% to 79%% marks':\n\n");

        for(i=0; ; i++){
            printf("Grading Range %d: ", i+1);
            scanf("%f %f %f", &lowerValue[i], &higherValue[i], &gradePoint[i]);
            count++;
            printf("Enter 99 to stop inputting grading ranges; otherwise any number: ");
            scanf("%d", &n);
            if(n==99) break;
        }

        printf("\nHighest mark of numbering range: ");
        scanf("%d", &highestNumber);

        printf("\nNumber of courses: ");
        scanf("%d", &course);

        printf("\n");

        for(i=0; i<course; i++){
            printf("Marks of course %d: ", i+1);
            scanf("%f", &mark[i]);
            printf("Credit hours of course %d: ", i+1);
            scanf("%f", &credit[i]);
        }

        for(i=0; i<course; i++){
            int j;
            for(j=0; j<count; j++){
                if((mark[i]*100)/highestNumber>=lowerValue[j] && (mark[i]*100)/highestNumber<=higherValue[j]) grade[i] = gradePoint[j];
            }
        }

        for(i=0; i<course; i++){
            sum += credit[i]*grade[i];
            count1 += credit[i];
        }

        printf("\nCGPA=%.2f\n", sum/count1);
    }


/*Starting to calculate GPA of a school student; where number of subjects are not fixed and user needs to input number of subjects.
Because, different classes of a school have different number of subjects.But common subjects are Bangla 1st+2nd paper and English 1st+2nd paper; so I added this two subjects.
Grading ranges are fixed in the program..Ranges are given below-
80%-100%=5, 70%-79%=4, 60%-69%=3.5, 50%-59%=3, 40%-49%=2, 33%-39%=1 and 0%-32%=FAIL*/
    else if(m==2){
        int course, i, fail = 0;
        float sum = 0.0, mark[20], grade[20];
        char subject[20][15] = {"Bangla 1st","Bangla 2nd", "English 1st", "English 2nd", "Math", "6", "7", "8", "9", "10", "11", "12", "13", "14", "15", "16", "17", "18", "19", "20"};

        float lowerValue[] = {80.0, 70.0, 60.0, 50.0, 40.0, 33.0};
        float higherValue[] = {100.0, 79.98, 69.98, 59.98, 49.98, 39.98};
        float gradePoint[] = {5.0, 4.0, 3.5, 3.0, 2.0, 1.0};

        printf("\nNumber of total subjects(with four subject): ");
        scanf("%d", &course);

        printf("\nEnter marks of *main* subjects:\n\n");
        for(i=0; i<course-1; i++){
            printf("Marks of subject %s: ", subject[i]);
            scanf("%f", &mark[i]);
        }

        printf("\nEnter number of *four* subject: ");
        scanf("%f", &mark[course-1]);

        mark[0] = (mark[0] + mark[1])/2.0;//average marks of Bangla 1st and Bangla 2nd paper
        mark[1] = (mark[2] + mark[3])/2.0;//average marks of English 1st and English 2nd paper

        for(i=0; i<=1; i++){
            int j; fail = 0;
            for(j=0; j<6; j++){
                if(mark[i]>=lowerValue[j] && mark[i]<=higherValue[j]){
                    grade[i] = gradePoint[j];
                    fail = 0;
                    break;
                }
                else fail = 1;
            }
            if(fail==1){
                printf("\nGPA=FAIL!\n");
                goto end;
            }
        }

        grade[2] = grade[3] = 0.0;

        for(i=4; i<course-1; i++){
            int j; fail = 0;
            for(j=0; j<6; j++){
                if(mark[i]>=lowerValue[j] && mark[i]<=higherValue[j]){
                    grade[i] = gradePoint[j];
                    fail = 0;
                    break;
                }
                else fail = 1;
            }
            if(fail==1){
                printf("\nGPA=FAIL!\n");
                goto end;
            }
        }

        for(i=course-1; i<course; i++){
            int j;
            for(j=0; j<6; j++){
                if(mark[i]>=lowerValue[j] && mark[i]<=higherValue[j]){
                    grade[i] = gradePoint[j] - 2.0;
                    break;
                }
            }
        }

        for(i=0; i<course; i++){
            sum += grade[i];
        }

        if(sum/(course-3) >= 5.0) printf("\nGPA=5.00\n");
        else printf("\nGPA=%.2f\n", sum/(course-3));
    }



/*Starting to calculate GPA of a COLLEGE student studying in science; where number of subjects are fixed(13) and GPA is been calculated to the average marks of subjects having dual part.
Grading ranges are fixed in the program..Ranges are given below-
80%-100%=5, 70%-79%=4, 60%-69%=3.5, 50%-59%=3, 40%-49%=2, 33%-39%=1 and 0%-32%=FAIL*/
    else if(m==3){
        int i, fail;

        float sum = 0.0, mark[13], grade[13];
        char subject[][20] = {"Bangla 1st","Bangla 2nd", "English 1st", "English 2nd", "ICT", "Math/Biology 1st", "Math/Biology 2nd", "Physics 1st", "Physics 2nd", "Chemistry 1st", "Chemistry 2nd", "Math/Biology 1st", "Math/Biology 2nd"};

        float lowerValue[] = {80.0, 70.0, 60.0, 50.0, 40.0, 33.0};
        float higherValue[] = {100.0, 79.98, 69.98, 59.98, 49.98, 39.98};
        float gradePoint[] = {5.0, 4.0, 3.5, 3.0, 2.0, 1.0};

        printf("\nEnter marks of *main* subjects:\n\n");
        for(i=0; i<=10; i++){
            printf("Marks of subject %s: ", subject[i]);
            scanf("%f", &mark[i]);
        }
        printf("\nEnter number of *four* subject:\n\n");
        for(i=11; i<=12; i++){
            printf("Marks of subject %s: ", subject[i]);
            scanf("%f", &mark[i]);
        }

        mark[0] = (mark[0] + mark[1])/2.0;//average marks of Bangla 1st and Bangla 2nd paper
        mark[1] = (mark[2] + mark[3])/2.0;//average marks of English 1st and English 2nd paper
        mark[2] = mark[4];//mark of ICT
        mark[3] = (mark[5] + mark[6])/2.0;//average marks of Math/bio 1st and Math/Bio 2nd paper
        mark[4] = (mark[7] + mark[8])/2.0;//average marks of Physics 1st and Physics 2nd paper
        mark[5] = (mark[9] + mark[10])/2.0;//average marks of Chemistry 1st and Chemistry 2nd paper
        mark[6] = (mark[11] + mark[12])/2.0;//average marks of Math/Bio(four) and Math/Bio(four) 2nd paper

        for(i=0; i<=5; i++){
            int j; fail = 0;
            for(j=0; j<6; j++){
                if(mark[i]>=lowerValue[j] && mark[i]<=higherValue[j]){
                    grade[i] = gradePoint[j];
                    fail = 0;
                    break;
                }
                else fail = 1;
            }
            if(fail == 1){
                printf("\nGPA=FAIL!\n");
                goto end;
            }
        }

        for(i=6; i<=6; i++){
            int j;
            for(j=0; j<6; j++){
                if(mark[i]>=lowerValue[j] && mark[i]<=higherValue[j]){
                    grade[i] = gradePoint[j] - 2.0;
                    break;
                }
            }
        }

        for(i=0; i<=6; i++){
            sum += grade[i];
        }

        if(sum/6 >= 5.0) printf("\nGPA=5.00\n");
        else printf("\nGPA=%.2f\n", sum/6);
    }

    else{
        printf("You entered wrong keyword!\n");
        goto read;
    }

    end:
    return 0;
}
