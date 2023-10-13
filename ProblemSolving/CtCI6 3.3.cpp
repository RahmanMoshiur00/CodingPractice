#include <bits/stdc++.h>
using namespace std;

template <typename T>
class SetOfStacks{
    private:
    vector< stack<T> > stk;
    int capacity;

    public:
    SetOfStacks(int _capacity){
        capacity = _capacity;
    }

    void PrintSize(){
        cout << "Total stacks = " << stk.size() << endl;
        cout << "Each stack size = ";
        for(int i=0; i<stk.size(); i++)
            cout << stk[i].size() << ' ';
        cout << endl;
    }

    void Push(T value){
        if(stk.size() == 0 || stk[stk.size() - 1].size() == capacity){ //empty stack or current stack is full
            // start a new stack and push into it
            stk.push_back(stack<T>());
        }
        stk[stk.size() - 1].push(value);
    }

    public: T Pop(){
        if(stk.size()>0 && !stk[stk.size() - 1].empty()){
            T value = stk[stk.size() - 1].top();
            stk[stk.size() - 1].pop();
            if(stk[stk.size() - 1].empty()){ //truncating the empty stack
                stk.pop_back();
            }
            return value;
        }
        return T(-1);
    }

    public: T PopAt(int index){ // 0-indexed
        if(index<stk.size() && !stk[index].empty()){
            T value = stk[index].top();
            stk[index].pop();
            if(stk[index].empty()){
                stk.pop_back();
            }
            return value;
        }
        else{ //invalid case
            return T(-1);
        }
    }

};


int main()
{
    SetOfStacks<int> st(5);

    for(int i=1; i<=12; i++){
        st.Push(i);
        st.PrintSize();
    }

    cout << st.Pop() << endl; //12
    cout << st.Pop() << endl; //11
    cout << st.Pop() << endl; //10
    cout << st.PopAt(0) << endl; //5
    cout << st.PopAt(0) << endl; // 4
}
