#include <bits/stdc++.h>
using namespace std;

class stringoperation
{
    char *str;
public:
    void getString(){
        char s[100000];
        gets(s);
        int n = strlen(s);
        str = new char[n];
        for(int i=0; i<n; i++){
            str[i] = s[i];
        }
        str[n] = '\0';
    }

    void show()
    {
        cout<<"String: "<<str<<endl;
    }

    stringoperation operator + (stringoperation A){
        stringoperation temp;
        int len1 = strlen(str);
        int len2 = strlen(A.str);
        int n =  len1 + len2;
        temp.str = new char[n];
        for(int i=0; i<len1; i++){
            temp.str[i] = str[i];
        }
        for(int i=0; i<len2; i++){
            temp.str[len1 + i] = A.str[i];
        }
        temp.str[n] = '\0';

        return temp;
    }

    void operator = (stringoperation A){
        int n = strlen(A.str);
        str = new char[n];

        for(int i=0; i<n; i++){
            str[i] = A.str[i];
        }
    }
};

int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);

    stringoperation A, B, C, D;

    A.getString();
    A.show();

    B = A;
    B.show();

    C.getString();
    C.show();

    D = A + C;

    D.show();

    return 0;
}

/*
Hello world!
Welcome to programming world!

*/
