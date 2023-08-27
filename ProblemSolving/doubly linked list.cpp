#include<bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node* prev;
    Node* next;
};

Node* root = NULL;
Node* leaf = NULL;

void insertAtStart(int value){
    Node* temp = new Node;
    temp->data = value;
    if(root==NULL){
        root = temp;
        temp->prev = root;
        leaf = root;
        temp->next = NULL;
    }
    else{
        temp->next = root;
        root = temp;
        temp->prev = root;
    }
}

void insertAtEnd(int value){
    Node* temp = new Node;
    temp->data = value;
    temp->next = NULL;
    if(root==NULL){
        root = temp;
        temp->prev = root;
        leaf = root;
    }
    else{
        temp->prev = leaf;
        Node* temp1 = leaf;
        temp1->next = temp;
        leaf = temp;
    }
}

void insertAtNthPosition(int value, int n){
    Node* temp = new Node;
    temp->data = value;
    Node* temp1 = root;
    for(int i=1; i<=n-2; i++) temp1 = temp1->next;
    temp->prev = temp1;
    temp->next = temp1->next;
    temp1->next = temp;
    temp1 = temp->next;
    temp1->prev = temp;
}

void deleteAtStart()
{
    Node* temp = root;
    root = temp->next;
    delete temp;
    temp = root;
    temp->prev = root;
}

void deleteAtEnd()
{
    Node* temp = leaf;
    temp = temp->prev;
    temp->next = NULL;
    Node* temp1 = leaf;
    delete temp1;
    leaf = temp;
}

void deleteNthElement(int n){
    Node* temp = root;
    for(int i=1; i<=n-2; i++) temp = temp->next;
    Node* temp1 = temp->next;
    temp->next = temp1->next;
    delete temp1;
    temp1 = temp->next;
    temp1->prev = temp;
}

void print(){
    Node* temp = root;
    while(temp != NULL){
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    cout<<endl;
}

int main()
{
    insertAtStart(3);
    print();
    insertAtEnd(4);
    print();
    insertAtStart(2);
    print();
    insertAtEnd(6);
    print();
    insertAtStart(1);
    print();
    insertAtNthPosition(5, 5);
    print();
    deleteAtStart();
    print();
    deleteAtEnd();
    print();
    insertAtEnd(6);
    insertAtStart(1);
    print();
    deleteNthElement(3);
    print();
    insertAtNthPosition(3, 3);
    print();
}
