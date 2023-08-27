#include <stdio.h>
#include <string.h>


void permutation(char str[], char str1[], int visited[],  int at, int n)
{
    int i;
    if(at == n){
        str1[n] = '\0';
        printf("%s\n", str1);
        return;
    }

    for(i=0; i<n; i++){
        if(!visited[i]){
            visited[i] = 1;
            str1[at] = str[i];
            permutation(str, str1, visited, at+1, n);
            visited[i] = 0;
        }
    }
}

int main()
{
    char str[10], str1[10];
    scanf("%s", str);

    int vis[10] = {0};

    int n = strlen(str);

    printf("\nPermutations:\n");
    permutation(str, str1, vis, 0, n);

    return 0;
}

/*
abc



abcd

abcd
acb
bac
bca
cab
cba

bacd

abcd


abcd
abdc
acbd
ac


abcd
abdc

abcd

*/
