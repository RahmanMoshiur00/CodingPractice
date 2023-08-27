/*
        Author: MD. Moshiur Rahman
        ID: 1602022
        Level-2 Semester-I
        CSE, HSTU
*/

//      TASK #01

#include <bits/stdc++.h>
using namespace std;

void task_1_1()
{
    string t = "A THING OF BEAUTY IS A JOY FOREVER";
    string p;

    int query;
    cout<<"Enter how many patterns you need to search: ";
    cin>>query; getchar();

    while(query--){
        cout<<"Enter pattern: ";
        getline(cin, p);
        int n = t.size() , m = p.size(), indx = 0;
        for(int i=0; i+m<n; i++){
            bool found = true;
            for(int j=0; j<m; j++){
                if(t[i+j] != p[j]){
                    found = false;
                    break;
                }
            }
            if(found){
                indx = i+1;
                break;
            }
        }
        if(indx) cout<<"'"<<p<<"'is found at position: "<<indx<<endl;
        else cout<<"'"<<p<<"' is not found in text"<<endl;
    }
}


void task_1_2()
{
    cout<<"Enter number of queries: ";
    int query;
    cin>>query;

    string s, t;
    int position;
    cout<<"Enter 1st_string, inserting_position, 2nd_string ["<<query<<" times]: "<<endl;
    while(query--){
        cin>>s>>position>>t;

        string temp;
        for(int i=0; i<position-1; i++) temp += s[i];
        for(int i=0; i<t.size(); i++) temp += t[i];
        for(int i=position-1; i<s.size(); i++) temp += s[i];

        s = temp;
        cout<<"OUTPUT: "<<s<<endl;
    }
}


void task_1_3()
{
    cout<<"Enter number of queries: ";
    int query;
    cin>>query;
    getchar();

    string s, t;
    int position;
    cout<<"Enter 1st_string, inserting_position, 2nd_string ["<<query<<" times]: "<<endl;
    while(query--){
        getline(cin, s);
        cin>>position; getchar();
        getline(cin, t);

        string temp;
        for(int i=0; i<position-1; i++) temp += s[i];
        for(int i=0; i<t.size(); i++) temp += t[i];
        for(int i=position-1; i<s.size(); i++) temp += s[i];

        s = temp;
        cout<<"OUTPUT: "<<s<<endl;
    }
}


int find_substring(string t, string p){
    int n = t.size() , m = p.size(), indx = -1;
    for(int i=0; i+m<n; i++){
        bool found = true;
        for(int j=0; j<m; j++){
            if(t[i+j] != p[j]){
                found = false;
                break;
            }
        }
        if(found){
            indx = i+1;
            break;
        }
    }

    return indx;
}

void task_1_4()
{
    cout<<"Enter number of queries: ";
    int query;
    cin>>query;

    string s;
    int position, len;

    while(query--){

        string temp, t, f;

        cout<<"Enter operation ID: 1.Delete 2.Replace"<<endl;
        int n;
        cin>>n; getchar();

        if(n==1){
            cout<<"Enter string, deletion_start_position, deletion_length: "<<endl;
            getline(cin, s);
            cin>>position>>len; getchar();
            for(int i=0; i<position-1; i++) temp += s[i];
            for(int i=position-1+len; i<s.size(); i++) temp += s[i];
        }
        else if(n==2){
            cout<<"Enter string, replaceable_string, 2nd_string: "<<endl;
            getline(cin, s);
            getline(cin, f);
            getline(cin, t);
            int indx = find_substring(s,f);
            len = f.size();
            for(int i=0; i<indx-1; i++) temp += s[i];
            for(int i=0; i<t.size(); i++) temp += t[i];
            for(int i=indx-1+len; i<s.size(); i++) temp += s[i];
        }

        s = temp;
        cout<<"OUTPUT: "<<s<<endl;
    }
}



void task_1_5()
{
    string t, p;

    int query;
    cout<<"Enter how many patterns you need to search: ";
    cin>>query;

    while(query--){
        cout<<"Enter pattern: ";
        cin>>p;
        cout<<"Enter text: ";
        cin>>t;

        int n = t.size() , m = p.size(), indx = 0;
        for(int i=0; i+m<n; i++){
            bool found = true;
            for(int j=0; j<m; j++){
                if(t[i+j] != p[j]){
                    found = false;
                    break;
                }
            }
            if(found){
                indx = i+1;
                break;
            }
        }
        if(indx) cout<<"'"<<p<<"' is found at position: "<<indx<<endl;
        else cout<<"'"<<p<<"' is not found in the text!"<<endl;
    }
}


int main()
{
    cout<<"*** Evaluating task 1.1 ***"<<endl;
    task_1_1();
    cout<<"\n*** Evaluating task 1.2 ***"<<endl;
    task_1_2();
    cout<<"\n*** Evaluating task 1.3 ***"<<endl;
    task_1_3();
    cout<<"\n*** Evaluating task 1.4 ***"<<endl;
    task_1_4();
    cout<<"\n*** Evaluating task 1.5 ***"<<endl;
    task_1_5();

    return 0;
}
