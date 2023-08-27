/*
        Author: MD. Moshiur Rahman
        ID: 1602022
        Level-2 Semester-I
        CSE, HSTU
*/

//      TASK #04

#include <bits/stdc++.h>
using namespace std;


void task_4_1()
{
    string s, t;
    cout<<"Enter a postfix arithmetic expression: ";
    getline(cin, s); //5, 6, 2, +, *, 12, 4, /, -
    s += ',';

    int stck[100000], pos = -1, n, a, b;

    for(int i=0; i<s.size(); i++){
        if(s[i]==','){
            if(t[0]>='0' && t[0]<='9'){
                n = stoi(t);
                stck[++pos] = n; //n is pushed to the stack
            }
            else{
                b = stck[pos--]; //popped the top element
                a = stck[pos--]; //popped the second top element

                if(t[0]=='+'){
                    stck[++pos] = a + b;
                }
                else if(t[0]=='-'){
                    stck[++pos] = a - b;
                }
                else if(t[0]=='*'){
                    stck[++pos] = a * b;
                }
                else if(t[0]=='/'){
                    stck[++pos] = a / b;
                }
            }

            t = "";
        }
        else if((s[i]>='0' && s[i]<='9') || s[i] != ' ') t += s[i];
    }

    cout<<"OUTPUT: "<<stck[0]<<endl;
}


int factorial(int n){
    if(n == 0) return 1;
    return n * factorial(n-1);
}
void task_4_2() //factorial
{
    cout<<"Enter a integer value to calculate factorial: ";
    int n; cin>>n;
    cout<<n<<"! = "<<factorial(n)<<endl;
}


int fibonacci(int n){
    if(n<=2) return 1;
    return fibonacci(n-1) + fibonacci(n-2);
}
void task_4_3() //fibonacci
{
    cout<<"Enter a integer value to calculate nth fibonacci: ";
    int n; cin>>n;

    cout<<"Fibonacci("<<n<<") = "<<fibonacci(n)<<endl;
}


void tower_of_hanoi(int n, char BEG, char AUX, char END){
    if(n==1){
        cout<<BEG<<" -> "<<END<<endl;
        return;
    }

    tower_of_hanoi(n-1, BEG, END, AUX);
    cout<<BEG<<" -> "<<END<<endl;
    tower_of_hanoi(n-1, AUX, BEG, END);
}
void task_4_4() //tower of hanoi
{
    cout<<"Enter the number of plates: ";
    int n; cin>>n;

    tower_of_hanoi(n, 'A', 'B', 'C');
}


void INSERT(char Q[], int& st, int& ed, char ch){
    if(ed >= 100000){
        cout<<"OVERFLOW! Queue if full"<<endl;
        return;
    }
    cout<<ch<<" is added!"<<endl;
    Q[ed] = ch;
    ed++;
}
void DELETE(char Q[], int& st, int& ed){
    if(st > ed){
        cout<<"UNDERFLOW! Queue is empty!"<<endl;
        return;
    }
    cout<<"Front is deleted!"<<endl;
    st++;
}
void queue_show(char Q[], int st, int ed){
    cout<<"Queue: ";
    for(int i=st; i<=ed; i++) cout<<Q[i]<<" ";
    cout<<endl;
}
void task_4_5()
{
    char Queue[100000];
    int st = 0 , ed = 0;

    INSERT(Queue, st, ed, 'A');
    queue_show(Queue, st, ed);
    INSERT(Queue, st, ed, 'B');
    queue_show(Queue, st, ed);
    INSERT(Queue, st, ed, 'C');
    queue_show(Queue, st, ed);
    DELETE(Queue, st, ed);
    queue_show(Queue, st, ed);
    INSERT(Queue, st, ed, 'D');
    queue_show(Queue, st, ed);
    INSERT(Queue, st, ed, 'E');
    queue_show(Queue, st, ed);
    DELETE(Queue, st, ed);
    queue_show(Queue, st, ed);
    DELETE(Queue, st, ed);
    INSERT(Queue, st, ed, 'F');
    queue_show(Queue, st, ed);
    DELETE(Queue, st, ed);
    queue_show(Queue, st, ed);
    INSERT(Queue, st, ed, 'G');
    queue_show(Queue, st, ed);
    INSERT(Queue, st, ed, 'H');
    queue_show(Queue, st, ed);
    DELETE(Queue, st, ed);
    queue_show(Queue, st, ed);
    DELETE(Queue, st, ed);
    queue_show(Queue, st, ed);
    INSERT(Queue, st, ed, 'k');
    queue_show(Queue, st, ed);
    DELETE(Queue, st, ed);
    queue_show(Queue, st, ed);
    DELETE(Queue, st, ed);
    queue_show(Queue, st, ed);
    DELETE(Queue, st, ed);
    queue_show(Queue, st, ed);
}


int main()
{

    cout<<"*** Evaluating task 4.1 ***"<<endl;
    task_4_1();

    cout<<"\n*** Evaluating task 4.2 ***"<<endl;
    task_4_2();

    cout<<"\n*** Evaluating task 4.3 ***"<<endl;
    task_4_3();

    cout<<"\n*** Evaluating task 4.4 ***"<<endl;
    task_4_4();

    cout<<"\n*** Evaluating task 4.5 ***"<<endl;
    task_4_5();

    return 0;
}
