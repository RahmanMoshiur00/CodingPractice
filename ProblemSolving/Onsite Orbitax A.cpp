// you can use includes, for example:

#include <bits/stdc++.h>
using namespace std;

#define debug if(1)


// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

struct data{
    string city, Time, extension;
    int id;
    data(){

    }
    data(string city_, string Time_, int id_, string extension_){
        city = city_;
        Time = Time_;
        id = id_;
        extension = extension_;
    }
};

bool cmp(data a, data b)
{
    if(a.city != b.city) return (a.city < b.city);
    return a.Time < b.Time;
}

string func(int val, int digit_count)
{
    string s = to_string(val);
    if(s.size() == digit_count) return s;

    int d = digit_count - int(s.size());
    string ans = "";
    while(d--) ans += '0';
    ans += s;

    return ans;
}

string solution(string &str) {
    // write your code in C++14 (g++ 6.2.0)

    vector<string> S;
    string tmp = "";
    for(int i=0; i<str.size(); i++){
        if(str[i]=='\n'){
            S.push_back(tmp);
            tmp = "";
            continue;
        }
        else tmp += str[i];
        if(i == str.size() - 1){
            S.push_back(tmp);
        }
    }

    debug{
        for(int i=0; i<S.size(); i++){
            cout << "Input string: " << S[i] << endl;
        }
    }

    int n = S.size();

    string ans[n];

    vector< data > v(n);

    string title, city, Time, extension, temp;
    int id, now_at = 0;
    for(int i=0; i<n; i++){
        temp = S[i];
        title = "", city = "", Time = "", extension = "";
        now_at = 0;
        for(int j=0; j<temp.size(); j++){
            if(now_at == 0){
                if(temp[j] == ',') now_at++, j++;
                if(now_at == 0){
                    title += temp[j];
                }
            }
            else if(now_at==1){
                if(temp[j]==',') now_at++, j++;
                if(now_at == 1){
                    city += temp[j];
                }
            }
            else{
                Time += temp[j];
            }
        }
        bool dot_found = false;
        for(int j=0; j<title.size(); j++){
            if(dot_found){
                extension += title[j];
            }
            if(title[j]=='.') dot_found = true;
        }

        v.push_back(data(city, Time, id, extension));
    }

    debug{
        for(int i=0; i<v.size(); i++){
            cout << "data: " << v[i].city << ' ' << v[i].Time << ' ' << v[i].id << ' ' << v[i].extension << endl;
        }
    }

    sort(v.begin(), v.end(), cmp);

    int counter , j;
    for(int i=0; i<n; i++){
        counter = 0;
        for(j=i; j<n; j++){
            if(v[i].city != v[j].city){
                break;
            }
            counter++;
        }
        for(int k=i, val = 1; k<j; k++){
            ans[v[k].id] = v[k].city + func(val, counter) + "." + v[k].extension;
        }
        i = j-1;
    }

    debug{
        for(int i=0; i<n; i++){
            cout << "Answer " << i << ": " << ans[i] << endl;
        }
    }


    string ret;
    for(int i=0; i<n; i++){
        ret += ans[i] + '\n';
    }

    return ret;
}
