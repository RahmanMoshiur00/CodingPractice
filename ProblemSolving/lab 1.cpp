#include <bits/stdc++.h>
using namespace std;

void INSERT(string& str, string ins, int n)
{
    string temp;

    for(int i=0; i<n-1; i++) temp += str[i];
    for(int i=0; i<ins.size(); i++) temp += ins[i];
    for(int i=n-1; i<str.size(); i++) temp += str[i];

    str = temp;
}


int main()
{
    string s = "I LOVE HSTU SO MUCH", inp;

    cout<<"Enter the position you want to insert a string: ";
    int n;
    cin>>n; getchar();

    getline(cin, inp);

    INSERT(s, inp, n);

    cout<<"OUTPUT STRING: "<<s<<endl;

    return 0;
}
