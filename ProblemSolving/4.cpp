//      TASK #04

#include <bits/stdc++.h>
using namespace std;


int factorial(int n){
    if(n == 0) return 1;
    return n * factorial(n-1);
}

int fibonacci(int n){
    if(n<=2) return 1;
    return fibonacci(n-1) + fibonacci(n-2);
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


int main()
{

    string s, t;
    cout<<"Enter a postfix arithmetic expression: ";
    getline(cin, s); //5, 6, 2, +, *, 12, 4, /, -
    s += ',';

    int st[100000], pos = -1, n, a, b;

    for(int i=0; i<s.size(); i++){
        if(s[i]==','){
            if(t[0]>='0' && t[0]<='9'){
                n = stoi(t);
                st[++pos] = n; //n is pushed to the stack
            }
            else{
                b = st[pos--]; //popped the top element
                a = st[pos--]; //popped the second top element

                if(t[0]=='+'){
                    st[++pos] = a + b;
                }
                else if(t[0]=='-'){
                    st[++pos] = a - b;
                }
                else if(t[0]=='*'){
                    st[++pos] = a * b;
                }
                else if(t[0]=='/'){
                    st[++pos] = a / b;
                }
            }

            t = "";
        }
        else if((s[i]>='0' && s[i]<='9') || s[i] != ' ') t += s[i];
    }

    cout<<"OUTPUT: "<<st[0]<<endl;

    cout<<"Enter a integer value to calculate factorial: ";
    cin>>n;
    cout<<n<<"! = "<<factorial(n)<<endl;

    cout<<"Enter a integer value to calculate nth fibonacci: ";
    cin>>n;

    cout<<"Fibonacci("<<n<<") = "<<fibonacci(n)<<endl;

    cout<<"Enter the number of plates: ";
    cin>>n;

    tower_of_hanoi(n, 'A', 'B', 'C');

    char Queue[100000];
    int start = 0 , ed = 0;

    INSERT(Queue, start, ed, 'A');
    queue_show(Queue, start, ed);
    INSERT(Queue, start, ed, 'B');
    queue_show(Queue, start, ed);
    INSERT(Queue, start, ed, 'C');
    queue_show(Queue, start, ed);
    DELETE(Queue, start, ed);
    queue_show(Queue, start, ed);
    INSERT(Queue, start, ed, 'D');
    queue_show(Queue, start, ed);
    INSERT(Queue, start, ed, 'E');
    queue_show(Queue, start, ed);
    DELETE(Queue, start, ed);
    queue_show(Queue, start, ed);
    DELETE(Queue, start, ed);
    INSERT(Queue, start, ed, 'F');
    queue_show(Queue, start, ed);
    DELETE(Queue, start, ed);
    queue_show(Queue, start, ed);
    INSERT(Queue, start, ed, 'G');
    queue_show(Queue, start, ed);
    INSERT(Queue, start, ed, 'H');
    queue_show(Queue, start, ed);
    DELETE(Queue, start, ed);
    queue_show(Queue, start, ed);
    DELETE(Queue, start, ed);
    queue_show(Queue, start, ed);
    INSERT(Queue, start, ed, 'k');
    queue_show(Queue, start, ed);
    DELETE(Queue, start, ed);
    queue_show(Queue, start, ed);
    DELETE(Queue, start, ed);
    queue_show(Queue, start, ed);
    DELETE(Queue, start, ed);
    queue_show(Queue, start, ed);

    return 0;
}

