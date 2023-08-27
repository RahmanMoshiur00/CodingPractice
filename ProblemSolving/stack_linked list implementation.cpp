#include<bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node* link;
};

Node* head = NULL;

void Push(int n)
{
    Node* temp = new Node;
    temp->data = n;
    temp->link = head;
    head = temp;
}

void Pop()
{
    if(head==NULL) return;
    Node* temp = head;
    head = temp->link;
    delete temp;
}

void Top()
{
    if(head==NULL){
        printf("Stack is empty!\n");
        return;
    }
    Node* temp = head;
    printf("Top element of this stack is: %d\n", temp->data);
}

void Print()
{
    Node* temp = head;
    if(head==NULL){
        printf("Stack is empty!\n");
        return;
    }
    printf("Stack:");
    while(1){
        printf(" %d", temp->data);
        if(temp->link==NULL) break;
        temp = temp->link;
    }
    printf("\n");
}

bool IsEmpty()
{
    if(head==NULL) return true;
    else return false;
}

int main()
{
    cout<<IsEmpty()<<endl;
    Push(3); Print();
    Push(7); Print();
    Top();
    Pop(); Print();
    Push(55); Print();
    Pop(); Print();
    cout<<IsEmpty()<<endl;
}
