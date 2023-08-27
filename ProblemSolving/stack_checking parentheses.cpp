#include<bits/stdc++.h>
using namespace std;

int main()
{
    string str;
    getline(cin, str);
    string open = "({[";
    string close = ")}]";

    stack<char> parenthese;

    int len = str.size();
    bool balanced = true;
    for(int i=0; i<len; i++){
        for(int j=0; j<3; j++){
            if(open[j]==str[i]){
                parenthese.push(str[i]);
                continue;
            }
        }
        for(int j=0; j<3; j++){
            if(close[j]==str[i]){
                if((parenthese.top() == '(' && str[i] == ')') || (parenthese.top() == '{' && str[i] == '}' ) || (parenthese.top()=='[' && str[i]==']')) parenthese.pop();
                else{
                    break;
                }
            }
        }
    }

    if(parenthese.empty()) printf("Parenthese are balanced!\n");
    else printf("Parentheses are not balanced!\n");

    return 0;
}
