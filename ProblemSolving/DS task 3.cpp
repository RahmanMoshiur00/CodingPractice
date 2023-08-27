/*
        Author: MD. Moshiur Rahman
        ID: 1602022
        Level-2 Semester-I
        CSE, HSTU
*/

//      TASK #03

#include <bits/stdc++.h>
using namespace std;

struct node{
    int data;
    node* link;
};

node* root = NULL;

void Insert(int n){
    node* temp = new node;

    if(root == NULL){
        temp->data = n;
        temp->link = NULL;
        root = temp;
    }
    else{
        temp->data = n;
        temp->link = root;
        root = temp;
    }
    cout<<"\n"<<n<<" is inserted successfully!"<<endl;
}

void Search(int n){
    node* temp = root;

    while(temp != NULL){
        if(temp->data == n){
            cout<<"\n"<<n<<" is present is the list!"<<endl;
            return;
        }
        temp = temp->link;
    }

    cout<<"\n"<<n<<" is not present is the list!"<<endl;
}

void Delete(int n){
    node *temp = root, *prev = root;

    while(temp != NULL){
        if(temp->data == n){
            if(temp == root) root = temp->link;
            else prev->link = temp->link;
            delete temp;
            cout<<"\n"<<n<<" is successfully deleted from the list!"<<endl;
            return;
        }
        prev = temp;
        temp = temp->link;
    }

    cout<<"\n"<<n<<" is not present in the list. So deletion is not possible!"<<endl;
}

void show_list()
{
    cout<<"LIST: ";
    node* temp = root;
    while(temp != NULL){
        cout<<temp->data<<" ";
        temp = temp->link;
    }
    cout<<"\n\n";
}


void command()
{
    cout<<"OPERATION MENU:: 1.Insert 2.Search 3.Delete 0.Exit"<<endl;
    cout<<"Enter command ID[0/1/2/3]: ";
    int n, cmd;
    cin>>cmd;

    if(cmd == 1){
        cout<<"Enter data to be inserted: ";
        cin>>n;
        Insert(n);
        show_list();
    }
    else if(cmd == 2){
        cout<<"Enter data to be searched: ";
        cin>>n;
        Search(n);
        show_list();
    }
    else if(cmd == 3){
        cout<<"Enter data to be deleted: ";
        cin>>n;
        Delete(n);
        show_list();
    }
    else if(cmd == 0) exit(0);
    else cout<<"Invalid command ID! Please, enter a valid command(0 or 1 or 2 or 3)."<<endl;

    command();
}

int main()
{
    command();

    return 0;
}

