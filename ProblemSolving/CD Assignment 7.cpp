/*
    7. Write a C/C++ program that reads text from a file, then delete the existing tabs (spaces)
and new line and save the output text file. Also count and print the number of deletion.
*/

#include <bits/stdc++.h>
using namespace std;

int main()
{
    ifstream input("input.txt");
    ofstream output("output.txt");

    string str, tmp;
    int deletions = 0;

    while(getline(input, str)){
        tmp = "";
        for(int i=0; i<str.size(); i++){
            if(str[i]!=' ' && str[i]!='\t'){
                tmp += str[i];
            }
            else{
                deletions++;
            }
        }
        if(!tmp.empty()) output << tmp;
    }

    cout << "Total number of deletions = " << deletions << endl;

    return 0;
}
