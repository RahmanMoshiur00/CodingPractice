#include<bits/stdc++.h>
using namespace std;

struct Node{
    Node* prev;
    Node* next;
    int data;
};

Node* head = NULL;

void insertAtBegin(int data){
    Node* temp = new Node;

    if(head==NULL){
        temp->data = data;
        temp->next = NULL;
        temp->prev = NULL;
        head = temp;
    }

    else{
        temp->data = data;
        temp->prev = NULL;
        temp->next = head;
        Node* temp1 = head;
        temp1->prev = temp;
        head = temp;
    }
}

void insertAtEnd(int data){
    Node* temp = new Node;
    if(head==NULL){
        temp->data = data;
        temp->next = NULL;
        temp->prev = NULL;
        head = temp;
    }
    else{
        Node* temp1 = head;
        while(temp1->next != NULL) temp1 = temp1->next;
        temp->data = data;
        temp->next = NULL;
        temp->prev = temp1;
        temp1->next = temp;
    }
}

void insertAtNthPosition(int n, int data){
    Node* temp = new Node;
    if(n==1){
        if(head==NULL){
            temp->data = data;
            temp->next = NULL;
            temp->prev = NULL;
            head = temp;
        }
        else{
            temp->data = data;
            temp->prev = NULL;
            temp->next = head;
            Node* temp1 = head;
            temp1->prev = temp;
            head = temp;
        }
    }

    else{
        Node* temp1 = head;
        for(int i=1; i<=n-2; i++) temp1 = temp1->next;
        if(temp1==NULL){
            printf("***List is overloaded!***\n");
            return;
        }
        else{
            temp->data = data;
            temp->next = temp1->next;
            temp->prev = temp1;
            temp1->next = temp;
            temp1 = temp->next;
            temp1->prev = temp;
        }
    }
}

void deleteEnd(){
    if(head==NULL){
        printf("***List is empty; nothing to delete!\n");
        return;
    }
    Node* temp = head;
    while(temp->next != NULL) temp = temp->next;
    Node* temp1;
    temp1 = temp->prev;
    temp1->next = NULL;
    delete temp;
}

void deleteBegin(){
    if(head==NULL){
        printf("***List is empty; nothing to delete!\n");
        return;
    }
    Node* temp = head;
    head = temp->next;
    temp = temp->next;
    temp->prev = NULL;
}

void deleteNthPosition(int n){
    Node* temp = head;
    if(head==NULL) printf("***List is empty; elements can't be deleted!\n");
    if(n==1){
        head = temp->next;
        temp = temp->next;
        temp->prev = NULL;
    }
    else{
        for(int i=1; i<=n-2; i++){
            temp = temp->next;
            if(temp == NULL){
                printf("***List is overloaded! Can't delete elements!\n");
                return;
            }
        }
        Node* temp1;
        temp1 = temp->next;
        temp->next = temp1->next;
        if(temp->next == NULL){
            delete temp1;
            return;
        }
        temp1 = temp1->next;
        temp1->prev = temp;
    }
}

void deleteElement(int data){
    int n = 0;
    Node* temp = head;
    while(1){
        n++;
        if(data == temp->data) break;
        if(temp == NULL){
            printf("***This element is absent in this list!\n");
            return;
        }
        temp = temp->next;
    }

    deleteNthPosition(n);
    return;
}

void Print()
{
    Node* temp1 = head;
    printf("List:");

    while(1){
        printf(" %d", temp1->data);
        if(temp1->next == NULL) break;
        temp1 = temp1->next;
    }
    printf("\n");
}


int main()
{
    insertAtBegin(3); Print();
    insertAtEnd(9); Print();
    insertAtNthPosition(2, 5); Print();
    insertAtNthPosition(3, 10); Print();
    deleteBegin(); Print();
    deleteEnd(); Print();
    insertAtNthPosition(1, 2); Print();
    insertAtNthPosition(2, 4); Print();
    deleteNthPosition(3); Print();
    deleteNthPosition(9); Print();
    insertAtNthPosition(1, 7); Print();
    deleteElement(10); Print();
    deleteElement(2); Print();

    return 0;
}
