/*
5. Write a C/C++ program that reads text from a file, then count and prints the number of
line exist in the inputted text file.
*/

#include <bits/stdc++.h>
using namespace std;

int main()
{
    ifstream myFile("input.txt"); //reading file texts
    string str;
    int lineCounter = 0; //line counter identifier

    while(getline(myFile, str)){
        lineCounter++;
    }

    cout << "Total number of lines = " << lineCounter << endl;

    return 0;
}
