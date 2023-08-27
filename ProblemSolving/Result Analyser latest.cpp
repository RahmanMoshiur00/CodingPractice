#include <bits/stdc++.h>
using namespace std;

int SEMESTER = 5; // number of result published semesters
double  CREDITS[] = {19.00, 19.25, 21.50, 20.00, 18.5, 18.5, 18.75, 19.25};

class Student{
 private:
    string id;
    vector<double> gpa;

 public:
    void set_id(string _id){
        id = _id;
    }
    void set_gpa(){
        int x;
        for(int i=0; i<SEMESTER; i++){
            cin >> x;
            gpa.push_back(x);
        }
    }
    double get_cgpa(){
        double up = 0.0, down = 0.0;
        for(int i=0; i<SEMESTER; i++){
            up += gpa[i] * CREDITS[i];
            down += CREDITS[i];
        }
        return (up/down);
    }
};


vector<Student> students; //STUDENT[i].first = name of the i-th student, STUDENT[i].second


int main()
{

}
