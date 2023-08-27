#include<bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node* link;
};

Node* head = NULL;
Node* tail = NULL;

void enqueue(int n)
{
    Node* temp = new Node;

    if(head==NULL){
        temp->data = n;
        temp->link = NULL;
        head = temp;
        tail = temp;
    }
    else{
        temp->data = n;
        temp->link = head;
        head = temp;
    }
}

void dequeue()
{
    Node* temp = head;
    if(head==NULL){
        cout<<"Queue is empty!"<<endl;
        return;
    }
    if(head==tail){
        head = tail = NULL;
        delete temp;
    }
    while(temp->link != tail) temp = temp->link;
    tail = temp;
    Node* temp1 = temp;
    temp1 = temp1->link;
    temp->link = NULL;
    delete temp1;
}

void Front()
{
    Node* temp = tail;
    if(head==NULL) cout<<"Queue is empty!\n";
    else cout<<"The front element of queue is: " << temp->data<<endl;
}

void isEmpty()
{
    if(head==NULL) cout<<"Queue is empty!"<<endl;
    else cout<<"Queue is not empty!"<<endl;
}

void print()
{
    Node* temp = head;
    cout<<"Queue:";
    while(temp != NULL){
        cout<<" "<<temp->data;
        temp = temp->link;
    }
    cout<<endl;
}

int main()
{
    dequeue(); print(); Front();
    enqueue(3); print(); Front();
    enqueue(7); print(); Front();
    dequeue(); print(); Front();
    isEmpty();
    Front();
    dequeue(); print(); Front();
    enqueue(26); print(); Front();
    enqueue(73); print(); Front();
    enqueue(67); print(); Front();
    dequeue(); print(); Front();
}
