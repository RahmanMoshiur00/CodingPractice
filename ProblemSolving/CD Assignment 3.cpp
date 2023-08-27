//3. Write a C/C++ program to test whether a given identifier is valid or not.

#include <bits/stdc++.h>
using namespace std;

int main()
{
    string str;
    getline(cin, str);

    bool isValid = true;

    if(!(str[0]=='_' || (str[0]>='a' && str[0]<='z') || (str[0]>='A' && str[0]<='Z'))){
        isValid = false;
    }
    for(int i=0; i<str.size(); i++){
        if(!(str[i]=='_' || (str[i]>='a' && str[i]<='z') || (str[i]>='A' && str[i]<='Z'))){
            isValid = false;
        }
    }

    if(isValid == true){
        cout << str << " is a valid identifier." << endl;
    }
    else{
        cout << str << " is NOT a valid identifier." << endl;
    }

    return 0;
}
