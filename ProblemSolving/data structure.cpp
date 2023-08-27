#include<bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node* next;
};

Node* head = NULL;
int insertionCounter = 0;

void InsertAtBeginning(int data){
    Node* temp = new Node;
    temp->data = data;
    temp->next = head;
    head = temp;
    insertionCounter++;
}

void InsertAtNthPosition(int data, int n){
    Node* temp = new Node;
    temp->data = data;
    temp->next = NULL;
    if(n==1){
        temp->next = head;
        head = temp;
        return;
    }
    Node* temp1 = head;
    for(int i=1; i<n-1; i++){
        temp1 = temp1->next;
    }
    temp->next = temp1->next;
    temp1->next = temp;
}

void InsertAtEnd(int data){
    Node* temp = new Node;
    temp->data = data;
    insertionCounter++;
    if(insertionCounter==1){
        head = temp;
        temp->next = NULL;
    }
    else{
        Node* temp1 = head;
        while(temp1->next != NULL){
            temp1 = temp1->next;
        }
        temp1->next = temp;
        temp->next = NULL;
    }
}

void DeleteNthNode(int n){
    Node* temp = head;
    if(n==1){
        head = temp->next;
        delete temp;
        return;
    }
    for(int i=0; i<n-2; i++) temp = temp->next; //temp is now n-1 th Node
    Node* temp1 = temp->next; // temp1 == n th node
    temp->next = temp1->next; //temp->next now is n th node, because temp1->next indicates n th node
    delete temp1; //it's optional
}

void DeleteAnElement(int data){
    Node* temp = new Node;
    temp->next = head;
    int n = 0;
    while(1){
        if(temp->next != NULL){
            break;
        }
        if(temp->data==data) break;
        else temp = temp->next;
        n++;
    }
    temp = head;
    if(n==1){
        head = temp->next;
        delete temp;
        return;
    }
    for(int i=0; i<n-2; i++) temp = temp->next; //temp is now n-1 th Node
    Node* temp1 = temp->next; // temp1 == n th node
    temp->next = temp1->next; //temp->next now is n th node, because temp1->next indicates n th node
    delete temp1; //it's optional

}

void Print(){
    Node* temp = head;
    printf("List is:");
    while(temp != NULL){
        printf(" %d", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main()
{
    InsertAtEnd(3); Print();
    InsertAtEnd(25); Print();
    InsertAtBeginning(77); Print();
    InsertAtEnd(34); Print();
    InsertAtBeginning(5); Print();
    InsertAtEnd(11); Print();
    InsertAtNthPosition(29, 4); Print();
    DeleteNthNode(1); Print();
    DeleteAnElement(25); Print();
    DeleteAnElement(77); Print();

    return 0;
}
