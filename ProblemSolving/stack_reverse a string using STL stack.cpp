#include<bits/stdc++.h>
using namespace std;

int main()
{
    char str[100];
    gets(str);
    int len = strlen(str);

    stack<char> st;

    for(int i=0; i<len; i++){
        st.push(str[i]);
    }
    for(int i=0; i<len; i++){
        printf("%c", st.top());
        st.pop();
    }
    printf("\n");

    return 0;
}
