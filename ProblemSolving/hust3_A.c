 #include<stdio.h>
int main()
{
    int i, j;
    char str[101];
    char vowels[]="aoyeui";
    while(gets(str)){
        for(i = 0; str[i]; i++){
            int judge = 0;
            if(str[i] >= 65 && str[i] <= 90) str[i] += 32;
            for(j = 0; j < 6; j++){
                if(str[i] == vowels[j])  judge = 1;
            }
            if(judge == 0) printf(".%c", str[i]);
        }
        puts("");
    }
    return 0;
}
