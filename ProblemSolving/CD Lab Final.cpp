/*
Write a C/C++/Java program that reads text from a file, then delete the
existing comment and save the output text file (without comment). Also
count and print the number of deletion.
*/

#include <bits/stdc++.h>
using namespace std;

int main()
{
    ifstream input("input.txt");
    ofstream output("output.txt");

    string str, temp;
    int deletions = 0;
    bool isComment = false;

    while(getline(input, str)){
        temp = "";
        isComment = false;
        for(int i=0; i+1<str.size(); i++){
            if(str[i]=='/' && str[i+1]=='/'){
                deletions++;
                isComment = true;
                break;
            }
            temp += str[i];
        }
        if(isComment == false && str.empty() == false) temp += str.back();
        if(temp.empty() == false) output << temp << endl;
    }

    cout << "Total number of deletions = " << deletions << endl;

    return 0;
}
