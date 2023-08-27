#include<bits/stdc++.h>
using namespace std;
#define pb      push_back
#define mxn     2 //number of semesters
double credit[] = {19.00, 19.25, 21.50, 20.00, 18.5, 18.5, 18.75, 19.25};

//input is given below the code

struct STD{
    string id;
    double sem[mxn], gpa;
    int ranks = 0;
};

vector<STD> data;

bool cmp(STD a, STD b){
    if(a.gpa > b.gpa) return true;
    else if(a.gpa == b.gpa){
        if(a.id < b.id) return true;
        else return false;
    }
    else return false;
}

void storeRank(){
    int sz = data.size(), r=1;
    data[0].ranks = 1;
    for(int i=1; i<sz; i++){
        if(data[i].gpa<data[i-1].gpa) data[i].ranks = ++r;
        else data[i].ranks = r;
    }
}

void sortedResult(){
    int sz = data.size();
    cout<<"\n Rank       ID          SEM01       SEM02       CGPA"<<endl;
    cout<<"-----------------------------------------------------"<<endl;
    for(int i=0; i<sz; i++){
        printf("%3d       ", data[i].ranks);
        cout<<data[i].id<<"       ";
        for(int j=0; j<mxn; j++) cout<<data[i].sem[j]<<"       ";
        cout<<fixed<<setprecision(3)<<data[i].gpa<<endl;  //printf("%.2lf\n", data[i].gpa);
    }
    cout<<endl;
}

void rangeSearch(double lo_gpa, double hi_gpa){
    int sz = data.size();
    vector<STD> res;
    for(int i=0; i<sz; i++){
        if(data[i].gpa>=lo_gpa && data[i].gpa<=hi_gpa){
            res.pb(data[i]);
        }
    }

    if(res.empty()){
        cout<<"\nNo entries found in GPA range of "<<lo_gpa<<" to "<<hi_gpa<<"\n"<<endl;
        return;
    }
    int s = res.size();
    cout<<"\n Rank       ID          SEM01       SEM02       CGPA"<<endl;
    cout<<"-----------------------------------------------------"<<endl;
    for(int i=0; i<s; i++){
        printf("%3d       ", res[i].ranks);
        cout<<res[i].id<<"       ";
        for(int j=0; j<mxn; j++) cout<<res[i].sem[j]<<"       ";
        cout<<fixed<<setprecision(3)<<res[i].gpa<<endl;  //printf("%.2lf\n", res[i].gpa);
    }
    cout<<endl;
    res.clear();
}

int rangeSearchCounter(double lo_gpa, double hi_gpa){
    int sz = data.size(), res = 0;
    for(int i=0; i<sz; i++){
        if(data[i].gpa>=lo_gpa && data[i].gpa<=hi_gpa){
            res++;
        }
    }
    return res;
}

void searchForID(string std_id){
    int sz = data.size();
    for(int i=0; i<sz; i++){
        if(data[i].id == std_id){
            cout<<"\n Rank       ID          SEM01       SEM02       CGPA"<<endl;
            cout<<"-----------------------------------------------------"<<endl;
            printf("%3d       ", data[i].ranks);
            cout<<data[i].id<<"       ";
            for(int j=0; j<mxn; j++) cout<<data[i].sem[j]<<"       ";
            cout<<fixed<<setprecision(3)<<data[i].gpa<<endl;  //printf("%.2lf\n", data[i].gpa);
            cout<<endl;
            return;
        }
    }
    cout<<"\nRequested ID("<<std_id<<") is not found!\n"<<endl;
}

void searchForGPA(double std_gpa){
    int sz = data.size();
    vector<STD> res;
    for(int i=0; i<sz; i++){
        if(data[i].gpa==std_gpa){
            res.pb(data[i]);
        }
    }

    if(res.empty()){
        cout<<"\nRequested GPA("<<std_gpa<<") is not found!\n"<<endl;
        return;
    }
    int s = res.size();
    cout<<"\n Rank       ID          SEM01       SEM02       CGPA"<<endl;
    cout<<"-----------------------------------------------------"<<endl;
    for(int i=0; i<s; i++){
        printf("%3d       ", res[i].ranks);
        cout<<res[i].id<<"       ";
        for(int j=0; j<mxn; j++) cout<<res[i].sem[j]<<"       ";
        cout<<fixed<<setprecision(3)<<res[i].gpa<<endl;  //printf("%.2lf\n", res[i].gpa);
    }
    cout<<endl;
    res.clear();
}

void searchForRank(int r){
    int sz = data.size();
    vector<STD> res;
    for(int i=0; i<sz; i++){
        if(data[i].ranks==r){
            res.pb(data[i]);
        }
    }

    if(res.empty()){
        cout<<"\nRequested Rank("<<r<<") is not found!\n"<<endl;
        return;
    }
    int s = res.size();
    cout<<"\n Rank       ID          SEM01       SEM02       CGPA"<<endl;
    cout<<"-----------------------------------------------------"<<endl;
    for(int i=0; i<s; i++){
        printf("%3d       ", res[i].ranks);
        cout<<res[i].id<<"       ";
        for(int j=0; j<mxn; j++) cout<<res[i].sem[j]<<"       ";
        cout<<fixed<<setprecision(3)<<res[i].gpa<<endl;  //printf("%.2lf\n", res[i].gpa);
    }
    cout<<endl;
    res.clear();
}

void totalSimulation(){
    int sz = data.size(), res;
    double star;
    cout<<"\nSimulation graph of obtained GPA(segmented by 0.25) and the gpa-student ratio of that range:\n";
    cout<<"3.75-4.00:  ";
    res = rangeSearchCounter(3.75, 4.00);
    star = (res/(sz*1.0))*50.00;
    for(int i=0; i<(int)round(star); i++) printf("*"); printf("\n");
    cout<<"\n3.50-3.75:  ";
    res = rangeSearchCounter(3.50, 3.74);
    star = (res/(sz*1.0))*50.00;
    for(int i=0; i<(int)round(star); i++) printf("*"); printf("\n");
    cout<<"\n3.25-3.50:  ";
    res = rangeSearchCounter(3.25, 3.49);
    star = (res/(sz*1.0))*50.00;
    for(int i=0; i<(int)round(star); i++) printf("*"); printf("\n");
    cout<<"\n3.00-3.25:  ";
    res = rangeSearchCounter(3.00, 3.24);
    star = (res/(sz*1.0))*50.00;
    for(int i=0; i<(int)round(star); i++) printf("*"); printf("\n");
    cout<<"\n2.75-3.00:  ";
    res = rangeSearchCounter(2.75, 2.99);
    star = (res/(sz*1.0))*50.00;
    for(int i=0; i<(int)round(star); i++) printf("*"); printf("\n");
    cout<<"\n2.50-2.75:  ";
    res = rangeSearchCounter(2.50, 2.74);
    star = (res/(sz*1.0))*50.00;
    for(int i=0; i<(int)round(star); i++) printf("*"); printf("\n");
    cout<<"\n2.25-2.50:  ";
    res = rangeSearchCounter(2.25, 2.49);
    star = (res/(sz*1.0))*50.00;
    for(int i=0; i<(int)round(star); i++) printf("*"); printf("\n");
    cout<<"\n2.00-2.25:  ";
    res = rangeSearchCounter(2.00, 2.24);
    star = (res/(sz*1.0))*50.00;
    for(int i=0; i<(int)round(star); i++) printf("*"); printf("\n\n");
}

void command(int key){
    if(key==1){
        sortedResult();
    }
    else if(key==2){
        cout<<"Enter two gpa inputs(smaller first, then larger) to perform range search: ";
        double lo, hi; cin>>lo>>hi;
        rangeSearch(lo, hi);
    }
    else if(key==3){
        cout<<"Enter ID to be searched: ";
        string s; cin>>s;
        searchForID(s);
    }
    else if(key==4){
        cout<<"Enter GPA to be searched: ";
        double g; cin>>g;
        searchForGPA(g);
    }
    else if(key==5){
        cout<<"Enter rank to be searched: ";
        int r; cin>>r;
        searchForRank(r);
    }
    else if(key==6){
        totalSimulation();
    }
    else if(key==7){
        system ("CLS");
    }
    else{
        cout<<"You've entered invalid keyword. Please, enter a valid(e.g. 1, 4, 2) key."<<endl;
    }
}

int main()
{

    STD student;

    cout<<fixed<<setprecision(3);
    cout<<"Enter ID and GPA(real number) of semesters sequentially[1stSem 2ndSem 3rdSem ... ...] respectively (separated by a space):"<<endl;
    cout<<"Enter 000 (adjacent three zero's) while you're finished giving inputs."<<endl;

    while(true){
        cin>>student.id;
        if(student.id == "000") break;
        for(int j=0; j<mxn; j++) cin>>student.sem[j];
        student.gpa = 0.0;
        double total_credit = 0.0;
        for(int j=0; j<mxn; j++) student.gpa += (student.sem[j] * credit[j]) , total_credit += credit[j];
        student.gpa /= total_credit;
        data.pb(student);
    }

    sort(data.begin(), data.end(), cmp); //sorting the data vector
    storeRank(); //storing ranks of the corresponding student

    cout<<"\nEnter a keyword given below to have your desired output(s)."<<endl;
    cout<<"1 :: Showing sorted and ranked result of all."<<endl;
    cout<<"2 :: Range search result of a given range of gpa."<<endl;
    cout<<"3 :: Search result for a particular ID."<<endl;
    cout<<"4 :: Search result for a particular GPA."<<endl;
    cout<<"5 :: Search result for a particular Rank."<<endl;
    cout<<"6 :: Total graphical simulation of the result analysis."<<endl;
    cout<<"7 :: Clear screen!"<<endl;
    cout<<"0 :: Exit"<<endl;

    int key;
    cout<<"Enter key: ";
    while(cin>>key && key){
        command(key);
        cout<<"Enter key: ";
    }

    cout<<"\nThank you for using this program! :)"<<endl;

    return 0;
}


/*
1602013 3.87 3.86
1602022 3.97 3.83
1602030 3.54 3.27
1602044 3.69 3.83
1602046 3.20 3.43
1702002 3.66 3.90
1702013 2.83 3.45
1702014 3.50 3.52
1702015 3.54 3.41
1702016 3.39 3.36
1702020 3.75 3.64
1702027 3.69 3.17
1702028 3.63 3.86
1702034 3.98 3.84
1702044 3.61 3.61
1702063 3.50 3.25
1702065 3.78 3.86
1702071 3.14 3.36
1702072 3.54 3.38
000
*/


