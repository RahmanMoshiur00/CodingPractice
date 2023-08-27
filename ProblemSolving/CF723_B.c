#include<stdio.h>

main()
{
    int n, i, j, out=0, in=0, temp=0, out_max=0;

    scanf("%d", &n);
    char str[n+1];
    scanf("%s", str);

    for(i=0; i<n; i++){
        if(str[i]=='('){
            for(j=i+1; ; j++){
                if((str[j]>='a' && str[j]<='z') || (str[j]>='A' && str[j]<='Z')){
                    temp++;
                }
                else if(str[j]=='_'){
                    if(temp>0) in++;
                    temp=0;
                }
                else if(str[j]==')'){
                    if(temp>0) in++;
                    temp=0;
                    break;
                }
            }
        }
    }

    int bra[255]={0};
    int k=0;

    for(i=0; i<n; i++){
        if(str[i]==')'){
            bra[k] = i;
            k++;
        }
    }

    int l=0;
    temp = 0;
    for(i=0; i<n; i++){
        if(str[i]=='('){
            i = bra[l];
            l++;
            continue;
        }
        else if((str[i]>='a' && str[i]<='z') || (str[i]>='A' && str[i]<='Z')){
            for(j=i; ; j++){
                if((str[j]>='a' && str[j]<='z') || (str[j]>='A' && str[j]<='Z')){
                    temp++;
                }
                else if(str[j]=='_' || str[j]=='(' || str[j]=='\0'){
                    if(temp>out_max) out_max = temp;
                    temp=0;
                    break;
                }
            }
        }
    }

    printf("%d %d\n", out_max, in);

    return 0;
}
