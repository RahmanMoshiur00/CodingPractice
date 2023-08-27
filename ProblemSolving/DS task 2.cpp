/*
        Author: MD. Moshiur Rahman
        ID: 1602022
        Level-2 Semester-I
        CSE, HSTU
*/

//      TASK #02

#include <bits/stdc++.h>
using namespace std;

void task_2_1() //bubble sort
{
    string s = "PEOPLE";
    int comparisons = 0 , interchanges = 0;

    for(int i=0; i+1<6; i++){
        for(int j=0; j+i+1<6; j++){
            comparisons++;
            if(s[j] >= s[j+1]){
                swap(s[j], s[j+1]);
                interchanges++;
            }
        }
    }
    cout<<"Sorted string: "<<s<<endl;
    cout<<"Comparisons: "<<comparisons<<"\n"<<"Interchanges: "<<interchanges<<endl;
}

void task_2_2() //binary search
{
    int data[] = {11, 22, 30, 33, 40, 44, 55, 60, 66, 77, 80, 88, 99};

    int n;
    cout<<"Enter item to be searched: ";
    cin>>n;

    int bg = 0, ed = 13, mid;
    while(bg<=ed){
        mid = (bg+ed)/2;
        if(data[mid] == n){
            cout<<n<<" is found at position: "<<mid+1<<endl;
            return;
        }
        else if(data[mid] > n) ed = mid - 1;
        else bg = mid + 1;
    }

    cout<<n<<" is not present in data!"<<endl;
}


int main()
{
    cout<<"*** Evaluating task 2.1 ***"<<endl;
    task_2_1();
    cout<<"\n*** Evaluating task 2.2 ***"<<endl;
    task_2_2();

    return 0;
}
