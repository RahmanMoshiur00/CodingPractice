//2. Write a C/C++ program to identify whether a given input line is a comment or not.

#include <bits/stdc++.h>
using namespace std;

int main()
{
    string str;

    getline(cin, str);

    if(str.size()>=2 && str[0]=='/' && str[1]=='/'){
        cout << "[" << str << "]" << " is a comment." << endl;
    }
    else if(str.size()>=4 && str[0]=='/' && str[1]=='*' && str[str.size()-2]=='*' && str[str.size()-1]=='/'){
        cout << "[" << str << "]" << " is a comment." << endl;
    }
    else{
        cout << "[" << str << "]" << " is NOT a comment." << endl;
    }

    return 0;
}
