#include <stdio.h>
#include <string.h>

int main()
{
    int tc;
    scanf("%d", &tc);

    char str[85], ch[85], num[85];

    while(tc--){
        scanf("%s", str);

        int len = strlen(str), ch_len = 0, num_len = 0, i, j, k;
        for(i=0; i<len; i++){
            if(str[i]>='a' && str[i]<='z'){
                ch[ch_len] = str[i];
                ch_len++;
            }
            else{
                num[num_len] = str[i];
                num_len++;
            }
        }

        for(i=0; i+1<ch_len; i++){
            for(j=0; j+i+1<ch_len; j++){
                if(ch[j]>ch[j+1]){
                    char t = ch[j];
                    ch[j] = ch[j+1];
                    ch[j+1] = t;
                }
            }
        }

        for(i=0; i+1<num_len; i++){
            for(j=0; j+i+1<num_len; j++){
                if(num[j]>num[j+1]){
                    char t = num[j];
                    num[j] = num[j+1];
                    num[j+1] = t;
                }
            }
        }

        j = 0, k = 0;
        for(i=0; i<len; i++){
            if(str[i]>='a' && str[i]<='z') printf("%c", ch[j++]);
            else printf("%c", num[k++]);
        }
        printf("\n");
    }

    return 0;
}
