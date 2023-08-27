#include<bits/stdc++.h>
using namespace std;

vector<string> pages;
int counter = 0;

void Visit(string input){
    stringstream ss(input);
    ss>>input;
    ss>>input;

    pages[++counter] = input;
    cout<<pages[counter]<<endl;

    for(int i=counter+1; i<101; i++) pages[i] = "";
}

void Back(){
    counter--;

    if(counter<0){
        counter++;
        printf("Ignored\n");
    }
    else cout<<pages[counter]<<endl;
}

void Forward()
{
    counter++;

    if(pages[counter] == ""){
        counter--;
        printf("Ignored\n");
    }
    else cout<<pages[counter]<<endl;
}

int main()
{
    int t;
    scanf("%d ", &t);

    for(int Case = 1; Case <= t; Case++){
        printf("Case %d:\n", Case);

        pages.resize(101);
        pages[0] = "http://www.lightoj.com/";

        string input;

        while(getline(cin, input) && input!="QUIT"){
            if(input[0] == 'V') Visit(input);
            else if(input == "BACK") Back();
            else if(input == "FORWARD") Forward();
        }

        counter = 0;
        pages.clear();
    }

    return 0;
}
