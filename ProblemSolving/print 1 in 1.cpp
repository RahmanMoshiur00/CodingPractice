#include <bits/stdc++.h>
using namespace std;

int main()
{
    cout << "Enter total number of pages: ";
    int n;
    cin >> n;

    system("clear");

    cout << "Total number of pages: " << n ;

    int last = n;
    if(n%2==1) last = n-1;
    vector<int> v1;
    for(int i=last; i>0; i-=2){
        v1.push_back(i);
    }
    cout << "\n\nFirst print: ";
    for(int i=0; i<v1.size(); i++){
        if(i!=0) cout << ",";
        cout << "" << v1[i];
    } cout << endl;


    vector<int> v2;
    for(int i=1; i<=n; i+=2){
        v2.push_back(i);
    }
    cout << "\nSecond print: ";
    for(int i=0; i<v2.size(); i++){
        if(i!=0) cout << ",";
        cout << "" << v2[i];
    } cout << "\n" << endl;

    cout << "\n";
    main();
}
