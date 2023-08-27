#include<bits/stdc++.h>
using namespace std;
#define mxn 1000000

int cmd=1, n = 0;

void show_list(){
    cout<<"0....Exit"<<endl;
    cout<<"1....View all elements"<<endl;
    cout<<"2....Insert new element"<<endl;
    cout<<"3....Search an element"<<endl;
    cout<<"4....Delete an element"<<endl;
    cout<<"5....Sort elements in ascending order"<<endl;
    cout<<"6....Sort elements in descending order"<<endl;
    cout<<"7....Find memory location of an element"<<endl;
}

void View(int* ar){
    cout<<"Current elements are: ";
    for(int i=1; i<=n; i++) cout<<ar[i]<<" ";
    cout<<endl;
}

void Insert(int* ar){
    cout<<"Please, enter a integer type data to be inserted: ";
    int x; cin>>x;
    ar[++n] = x;
}

void Search(int* ar){
    cout<<"Enter a data to be searched: ";
    int x; cin>>x;
    for(int i=1; i<=n; i++){
        if(x==ar[i]){
            cout<<x<<" is found."<<endl;
            return;
        }
    }
    cout<<x<<" is not found!"<<endl;
}

void Delete(int* ar){
    cout<<"Enter a data to be deleted: ";
    int x, idx = 0; cin>>x;
    for(int i=1; i<=n; i++){
        if(x==ar[i]){
            idx = i;
            n--;
            break;
        }
    }
    if(idx){
        for(int i=idx; i<=n; i++){
            ar[i] = ar[i+1];
        }
        cout<<x<<" is deleted successfully!"<<endl;
    }
    else cout<<x<<" is not found!"<<endl;
}

void Sort_asc(int* ar){
    for(int i=1; i<=n; i++){
        for(int j=i+1; j<=n; j++){
            if(ar[i]>ar[j]) swap(ar[i], ar[j]);
        }
    }
    cout<<"Elements are sorted in ascending order!"<<endl;
}

void Sort_des(int* ar){
    for(int i=1; i<=n; i++){
        for(int j=i+1; j<=n; j++){
            if(ar[i]<ar[j]) swap(ar[i], ar[j]);
        }
    }
    cout<<"Elements are sorted in descending order!"<<endl;
}

void MemLoc(int* ar){
    cout<<"Enter the index what for you want to know memory location: ";
    int x; cin>>x;
    if(x<1 || x>n) cout<<"Sorry! No such index is present!"<<endl;
    else cout<<"Desired memory location is = "<<&ar[x]<<endl;
}

void perform(int* ar){
    cout<<endl;
    if(cmd<1 || cmd>7) cout<<"Sorry! You entered an invalid keyword!"<<endl;
    else if(cmd==1) View(ar);
    else if(cmd==2) Insert(ar);
    else if(cmd==3) Search(ar);
    else if(cmd==4) Delete(ar);
    else if(cmd==5) Sort_asc(ar);
    else if(cmd==6) Sort_des(ar);
    else if(cmd==7) MemLoc(ar);
    cout<<endl;
}

void clear_screen(){
    char ch = getchar();
    cout<<"Press any key to clear screen: ";
    char chh = getchar();
    system("CLS");
}

int main()
{
    int *arr;
    arr = new int [mxn]; //dynamic memory allocation of 10^6 elements

    while(true){
        show_list();

        cout<<"Please, enter a valid keyword from the given list: ";
        cin>>cmd;

        if(cmd == 0) break;

        perform(arr);
        clear_screen();
    }

    cout<<"\nThank you for using this system! :)"<<endl;

    return 0;
}
