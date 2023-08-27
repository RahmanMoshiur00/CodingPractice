#include <bits/stdc++.h>
using namespace std;

struct node{
    int value;
    node* next;
};

node* root = NULL;

void Insert(int n){
    node* temp = new node;

    if(root == NULL){
        temp->value = n;
        temp->next = NULL;
        root = temp;
    }
    else{
        temp->value = n;
        temp->next = root;
        root = temp;
    }
    cout<<"\n"<<n<<" is inserted successfully!"<<endl;
}

void Search(int n){
    node* temp = root;

    while(temp != NULL){
        if(temp->value == n){
            cout<<"\n"<<n<<" is present is the list!"<<endl;
            return;
        }
        temp = temp->next;
    }

    cout<<"\n"<<n<<" is not present is the list!"<<endl;
}

void Delete(int n){
    node *temp = root, *prev = root;

    while(temp != NULL){
        if(temp->value == n){
            if(temp == root) root = temp->next;
            else prev->next = temp->next;
            delete temp;
            cout<<"\n"<<n<<" is successfully deleted from the list!"<<endl;
            return;
        }
        prev = temp;
        temp = temp->next;
    }

    cout<<"\n"<<n<<" is not present in the list. So deletion is not possible!"<<endl;
}

void show_list()
{
    cout<<"LIST: ";
    node* temp = root;
    while(temp != NULL){
        cout<<temp->value<<" ";
        temp = temp->next;
    }
    cout<<"\n\n";
}


int main()
{
    int n, cmd;
    cout<<"MENU:: 1.Insertion 2.Searching 3.Delete 0.Exit"<<endl;
    cout<<"Enter command ID: ";

    while(cin>>cmd && cmd){


        if(cmd == 1){
            cout<<"Enter value to be inserted: ";
            cin>>n;
            Insert(n);
            show_list();
        }
        else if(cmd == 2){
            cout<<"Enter value to be searched: ";
            cin>>n;
            Search(n);
            show_list();
        }
        else if(cmd == 3){
            cout<<"Enter value to be deleted: ";
            cin>>n;
            Delete(n);
            show_list();
        }
        else cout<<"Enter valid command!"<<endl;

        cout<<"MENU:: 1.Insertion 2.Searching 3.Delete 0.Exit"<<endl;
        cout<<"Enter command ID: ";
    }

    return 0;
}
