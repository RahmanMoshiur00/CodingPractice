/*
4. Write a C/C++ program that reads text from a file, then count and prints the number of
character exist in the inputted text file.
*/

#include <bits/stdc++.h>
using namespace std;

int main()
{
    ifstream myFile("input.txt");
    string str;
    int char_count = 0;

    while(getline(myFile, str)){
        char_count += str.size();
    }

    cout << "Total characters = " << char_count << endl;

    return 0;
}
