#include<iostream>

using namespace std;

int Size = 3;

template <class t>
class vectr
{
    t* v;
public:
    vectr(){
        v = new t[Size];
        for(int i=0; i<Size; i++){
            v[i] = 0;
        }
    }
    vectr(t* a){
        v = new t[Size];
        for(int i=0; i<Size; i++) v[i] = a[i];
    }
    /*t operator*(vectr &y){
        t sum = 0;
        for(int i=0; i<Size; i++){
            sum += this->v[i] * y.v[i];
        }
        return sum;
    }*/
    void display(){
        for(int i=0; i<Size; i++) cout<<v[i]<<"  ";
        //cout<<endl;
    }
};

int main()
{
    int x[3] = {1,2,3};
    int y[3] = {2, 3, 4};
    vectr <int> v1(x);
    vectr <int> v2(y);
    cout<<"v1 = ";
    v1.display();
    cout<<"v2 = ";
    v2.display();
    //cout<<"v1 * v2 = "<<v1*v2<<endl;
    return 0;
}
