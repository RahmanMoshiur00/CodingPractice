#include <bits/stdc++.h>
using namespace std;

struct node{
    char data;
    node* next;
};

node* root = NULL;
node* last = NULL;

void INSERT(char ch)
{
    node* temp = new node;

    temp->data = ch;
    temp->next = NULL;

    if(root == NULL){
        root = temp;
        last = temp;
    }
    else{
        last->next = temp;
        last = temp;
    }
}

void show_list()
{
    node* temp = new node;
    temp = root;

    cout<<"LINKED LIST:";
    while(temp != NULL){
        cout<<" "<<temp->data;
        temp = temp->next;
    }
    cout<<endl;
}


int main()
{
    cout<<"Enter characters (use '0' as terminator of input):"<<endl;
    char ch;

    while(cin>>ch && ch!='0'){
        INSERT(ch);
    }

    show_list();

    return 0;
}
