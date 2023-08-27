/*
6. Write a C/C++ program that reads text from a file, then delete the existing comment and
save the output text file (without comment). Also count and print the number of deletion.
*/

#include <bits/stdc++.h>
using namespace std;

int main()
{
    ifstream input("input.txt");
    ofstream output("output.txt");

    vector<string> str;
    string s, tmp;

    int commentAt = -1;
    while(getline(input, s)){
        commentAt = -1;
        for(int i=0; i+1<s.size(); i++){
            if(s[i]=='/' && s[i+1]=='/'){
                commentAt = i;
                break;
            }
        }
        if(commentAt != -1){
            tmp = "";
            for(int i=0; i<commentAt; i++) tmp += s[i];
            output << tmp << endl;
        }
        else{
            output << s << endl;
        }
    }

    return 0;
}
