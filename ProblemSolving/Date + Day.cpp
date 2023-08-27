#include <bits/stdc++.h>
using namespace std;

bool isLeapYear(int yy)
{
    if(yy%400==0) return true;
    if(yy%4==0 && yy%100!=0) return true;
    return false;
}

int main()
{
    int dd, mm, yy;
    cout << "Enter 'day month year' in this order: ";
    cin >> dd >> mm >> yy;

    cout << "Enter how many days you want to add to the current date: ";
    int n; cin >> n;

    int month[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    for(int i=0; i<n; i++){
        dd++;
        if(dd > month[mm]){
            mm++;
            dd = 1;
        }
        if(mm > 12){
            yy++;
            if(isLeapYear(yy)) month[2] = 29;
            else month[2] = 28;
            mm = 1;
        }
    }

    cout << "Desired date: " << dd << "/" << mm << "/" << yy << endl;
}
