#include <bits/stdc++.h>
using namespace std;

class Student{
private:
    int subjects;
    double cgpa;
    vector<double> gpa, total_marks, obtained_marks;
    vector<string> subject_names;

public:
    string name, id, dateOfBirth, fathers_name, mothers_name;
    int _class, roll;

    string newline(){ // to avoid data loss
        string s;
        getline(cin, s);
        if(s == "") getline(cin, s);
        return s;
    }
    void input_id(){
        cout<<"Enter ID: "; cin>>id;
    }
    void input_name(){
        cout<<"Enter Name: ";
        name = newline();
    }
    void input_roll(){
        cout<<"Enter Roll: "; cin>>roll;
    }
    void input_dateOfBirth(){
        cout<<"Enter date of birth: ";
        dateOfBirth = newline();
    }
    void input_fathers_name(){
        cout<<"Enter father's name: ";
        fathers_name = newline();
    }
    void input_mathers_name(){
        cout<<"Enter mother's name: ";
        mothers_name = newline();
    }
    void input_class(int c)
    {
        _class = c;
    }
    void input_class(){
        cout<<"Enter class: "; cin >> _class;
    }
};

void classwise_subject_initialization(){
    cout<<"Enter class: ";
    int Class; cin>>Class;
    cout<<"Enter number of subjects: ";
    int sub; cin>>sub;

}

void initialize_a_student()
{
    input_id();
    input_name();
    input_class();
    input_roll();
    input_dateOfBirth();
    input_fathers_name();
    input_mothers_name();
}

void initialize_class_subjects()
{
    // how many subjects, subjects names
}
void classwise_student_profile_initialization(vector<Student>& st, int Class, int n)
{
    Student temp;
    while(n--){
        temp.basic_input();
        temp.input_class(Class);
        st.push_back(temp);
    }
}

void add_a_student()
{
    // add a student
}

