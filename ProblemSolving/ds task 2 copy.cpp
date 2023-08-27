#include <bits/stdc++.h>
using namespace std;


int main()
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


    int data[] = {11, 22, 30, 33, 40, 44, 55, 60, 66, 77, 80, 88, 99};

    int n;
    cout<<"Enter item to be searched: ";
    cin>>n;

    int bg = 0, ed = 13, mid;
    bool found = false;

    while(bg<=ed){
        mid = (bg+ed)/2;
        if(data[mid] == n){
            cout<<n<<" is found at position: "<<mid+1<<endl;
            found = true;
            break;
        }
        else if(data[mid] > n) ed = mid - 1;
        else bg = mid + 1;
    }

    if(found == false) cout<<n<<" is not present in data!"<<endl;

    return 0;
}
