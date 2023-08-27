#include<cstdio>
#include<sstream>
#include<iostream>
#include<string>
#include<vector>
using namespace std;

#define intt long long

intt factorial(intt n){
    intt fact=1;
    for(intt i=2; i<=n; i++) fact *= i;
    return fact;
}

int main()
{
    intt t;
    scanf("%lld ", &t);
    vector<string> words;
    while(t--){
        string str;
        getline(cin, str);
        stringstream ss(str);
        while(ss>>str) words.push_back(str);
        intt counter, sz = words.size(), res = 1;
        for(intt i=0; i<sz; i++){
            counter = 1;
            for(intt j=i+1; j<sz; j++){
                if((words[i] != "") && (words[i]==words[j])){
                    counter++;
                    words[j] = "";
                }
            }
            res *= factorial(counter);
        }
        printf("1/%lld\n", factorial(sz)/res);
        words.clear();
    }

    return 0;
}
