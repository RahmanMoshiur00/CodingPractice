// Author: Md. Moshiur Rahman

/*
8. Imagine the syntax of a programming language construct such as while-loop --
    while ( condition )
    begin
        statement;
    end
where while, begin, end are keywords; condition can be a single comparison expression
(such as x == 10, etc.); and statement is the assignment to a location the result of a single
arithmetic operation (eg., a = 5 * b).
Write a C/C++ program that verifies whether the input follows the above syntax.
*/

#include <bits/stdc++.h>
using namespace std;

bool isPresent(string a, string b, int x){
    for(int i=0, j=x; i<a.size(); i++, j++){
        if(j>=b.size() || a[i]!=b[j]) return false;
    }
    return true;
}

bool isValidCondition(string s){
    /*
        Condtion validation code could be here; but as conditions can be of VARIOUS types, so I opted not to verify them
    */

    string left, cond, right;
    if(s.back() != ';') return false;

    for(int i=0; i<s.size(); i++){
        if(s[i]=='=' || s[i]=='>' || s[i]=='<' || s[i]=='!'){
            break;
        }
        left += s[i];
    }

    for(int i=0; i<s.size(); i++){
        if(s[i]=='=' || s[i]=='>' || s[i]=='<' || s[i]=='!'){
            cond += s[i];
            if(i+1<s.size() && (s[i+1]=='=' || s[i+1]=='>' || s[i+1]=='<' || s[i+1]=='!')){
                cond += s[i+1];
                if(i+2<s.size() && (s[i+2]=='=' || s[i+2]=='>' || s[i+2]=='<' || s[i+2]=='!')){
                    return false; // conditional operators can't be more than length 2
                }
                for(int j=i+2; j<s.size(); j++){
                    if(s[i]==';'){
                        if(i+1<s.size()) return false;
                        break;
                    }
                    right += s[j];
                }
            }
        }
    }

    return true;
}

bool isValidStatement(string s){
    /*
        Statement validation code could be here; but as statements can be of VARIOUS types, so I opted not to verify them
    */
    return true;
}

int main()
{
    ifstream myFile("input.txt");

    vector<string> str;
    string s, tmp;

    while(getline(myFile, s)){ // reading input
        tmp = "";
        for(int i=0; i<s.size(); i++){ // removing spaces from input
            if(s[i] != ' ') tmp += s[i];
        }
        if(tmp.size() > 0) str.push_back(tmp);
    }

    if(str.size() < 3){ // less number of lines
        cout << "This input does NOT follow the given syntax." << endl;
        return 0;
    }

    // checking   while ( condition )
    if(isPresent("while(", str[0], 0) == false){
        cout << "This input does NOT follow the given syntax." << endl;
        return 0;
    }

    int started = 0;
    string condition = "", statement = "";
    for(int i=0; i<str[0].size(); i++){
        if(started==0 && str[0][i]=='('){
            started = 1;
            continue;
        }
        if(started==1 && str[0][i]==')'){
            started = 2;
            continue;
        }
        if(started==2){ //extra characters after "while ( condition )"
            cout << "This input does NOT follow the given syntax." << endl;
            return 0;
        }
        if(started==1) condition += str[0][i];
    }
    if(isValidCondition(condition) == false){ //couldn't write isValidCondition, because conditions can be of many diff types
        cout << "This input does NOT follow the given syntax." << endl;
        return 0;
    }

    if(str[1] != "begin" || str[str.size()-1] != "end"){
        cout << "This input does NOT follow the given syntax." << endl;
        return 0;
    }

    for(int i=2; i-1<str.size(); i++){
        if(isValidStatement(str[i]) == false){ //coudn't write isValidStatement, because statements can be of many diff types
            cout << "This input does NOT follow the given syntax." << endl;
            return 0;
        }
    }

    cout << "This input follows the given syntax." << endl;
    return 0;
}
