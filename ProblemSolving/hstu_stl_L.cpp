#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    scanf("%d", &t);

    vector<int> d;
    map<int, string> date;

    while(t--){
        string name;
        int day, month, year;
        cin>>name>>day>>month>>year;
        date[day+(month*30)+(year*30*12)] = name;
        d.push_back(day+(month*30)+(year*30*12));
    }

    vector<int>:: iterator Max = max_element(d.begin(), d.end());
    vector<int>:: iterator Min = min_element(d.begin(), d.end());

    cout<<date[*Max]<<endl<<date[*Min]<<endl;

    return 0;
}
