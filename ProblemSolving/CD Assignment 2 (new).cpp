#include <bits/stdc++.h>
using namespace std;

int main()
{
    ifstream myFile("input.txt"); //reading input.txt file
    string str, str1;
    bool commentStarts = false;

    while(getline(myFile, str)){
        if(commentStarts == true){
            str1 = "";
            for(int i=0; i+1<str.size(); i++){
                str1 += str[i];
                if(str[i]=='*' && str[i+1]=='/'){
                    str1 += str[i+1];
                    commentStarts = false;
                    break;
                }
            }
            cout << str1 << "  " << "*This line is a comment*" << endl;
        }
        for(int i=0; i+1<str.size(); i++){
            if(str[i]=='/' && str[i+1]=='*'){
                str1 = "";
                while(i<str.size()) str1 += str[i++];
                cout << str1 << "  " << "*This line is a comment*" << endl;
                commentStarts = true;
            }
            if(str[i]=='/' && str[i+1]=='/'){
                str1 = "";
                while(i<str.size()) str1 += str[i++];
                cout << str1 << "  " << "*This line is a comment*" << endl;
                commentStarts = false;
            }

        }
    }
}

