#include<bits/stdc++.h>
using namespace std;

int main()
{
    map<string, string> dic;

    string str, sec;
    getline(cin, str);

    while(str != ""){
         stringstream ss(str);
         ss>>str>>sec;
         dic[sec] = str;
         getline(cin, str);
    }

    while(cin>>str){
        if(dic[str]=="") printf("eh\n");
        else printf("%s\n", dic[str].c_str());
    }
    return 0;

}
