#include <bits/stdc++.h>
using namespace std;

int main()
{
    cout << "Enter page numbers [start end]: ";
    int st, ed;
    cin >> st >> ed;

    system("clear");
    cout << "Total number of pages: [" << st << " " << ed << "] = " << ed-st+1 << endl;


    vector<int> forwarded;
    for(int i=st; i<=ed; i+=2) forwarded.push_back(i);

    vector<int> reversed;
    for(int i=st+1; i<=ed; i+=2) reversed.push_back(i);
    reverse(reversed.begin(), reversed.end());

    cout << "\nFirst print: ";
    for(int i=0; i<reversed.size(); i++){
        if(i!=0) cout << ',';
        cout << reversed[i];
    } cout << endl;

    cout << "\nSecond print: ";
    for(int i=0; i<forwarded.size(); i++){
        if(i!=0) cout << ',';
        cout << forwarded[i];
    } cout << "\n" << endl;

    main();
}

