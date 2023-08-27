#include<iostream>
#include<stdio.h>
using namespace std;

int count_x(char* p, char x)
// count the number of occurrences of x in p[]
// p is assumed to point to a zero-ter minated array of char (or to nothing)
{
if (p==NULL) return 0;
int count = 0;
for (; *p!=NULL; ++p)
if (*p==x)
++count;
return count;
}

int main()
{
    char n[10] = "munna";
    char c = 'n';
    cout<<count_x(n, c)<<endl;
}
