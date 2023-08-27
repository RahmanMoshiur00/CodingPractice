#include<bits/stdc++.h>
using namespace std;

int main()
{
    string input;
    string output = "";
    getline(cin, input);
    int len = input.size();
    for(int i=0; i<len; i++) if(input[i] != ' ') output += input[i];
    cout<<output<<endl;

    return 0;
}
