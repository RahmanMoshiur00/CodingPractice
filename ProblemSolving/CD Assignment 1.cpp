/*
1. Write a C/C++ program that reads text from a file and prints on the terminal each input
line, preceded by the line number. The output will look like -
    1 This is the first trial line in the file,
    2 and this is the second line.
*/

#include <bits/stdc++.h>
using namespace std;

int main()
{
    ifstream myFile("input.txt"); //reading file texts
    string str;
    int lineCounter = 0; //line counter identifier

    while(getline(myFile, str)){
        cout << ++lineCounter << "  " << str << endl;
    }

    return 0;
}
