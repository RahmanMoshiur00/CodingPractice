#include<bits/stdc++.h>
using namespace std;

int main()
{
    set<string> dict;
    string input;
    while(cin>>input){
        string word = "";
        for(int i=0; i<input.size(); i++){
            if(input[i]>='A' && input[i]<='Z') input[i] += 32;
            if(input[i]>='a' && input[i]<='z') word += input[i];
            else if(word!=""){
                dict.insert(word);
                word = "";
            }
        }
        if(word!="") dict.insert(word);
    }
    for(set<string>:: iterator itr = dict.begin(); itr!=dict.end(); itr++) cout<<*itr<<"\n";

    return 0;
}
