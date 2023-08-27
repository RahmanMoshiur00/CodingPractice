#include<bits/stdc++.h>
using namespace std;

vector<int> arr;

void Push(int n)
{
    arr.push_back(n);
}

void Pop()
{
    arr.pop_back();
}

int Top()
{
     int len = arr.size();
     cout<<"Top element of this stack: "<<arr[len-1]<<endl;
}

void Print()
{
    int len = arr.size();
    printf("Stack:");
    for(int i=len-1; i>=0; i--) printf(" %d", arr[i]);
    printf("\n");
}

bool IsEmpty()
{
    if(arr.size()<1) return true;
    else return false;
}

int main()
{
    cout<<IsEmpty()<<endl;
    Push(3); Print();
    Push(7); Print();
    Top();
    Pop(); Print();
    Push(55); Print();
    Pop(); Print();
    cout<<IsEmpty()<<endl;

    return 0;
}
