#include <bits/stdc++.h>
using namespace std;

class base1
{
  protected:
    int a;
  public:
    void get_base1(){
        cin>>a;
    }
    void show_base1(){
        cout<<"a = "<<a<<endl;
    }
};

class base2
{
  protected:
    int b;
  public:
    void get_base2(){
        cin>>b;
    }
    void show_base2(){
        cout<<"b = "<<b<<endl;
    }
};

class derived : public base1 , public base2
{
protected:
    int c;
public:
    void get(){
        get_base1();
        get_base2();
    }
    void add(){
        c = a + b;
    }
    void show(){
        cout<<"a = "<<a<<endl;
        cout<<"b = "<<b<<endl;
        cout<<"c = "<<c<<endl;
    }
};

int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);

    derived x;
    x.get();
    x.add();
    x.show();

    return 0;
}

//5 7
