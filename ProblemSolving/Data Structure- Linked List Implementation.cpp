#include<bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node* link;
};

Node* head = NULL;
int counter = 0;

void insertAtBegin(int value){
    counter++;
    Node* temp = new Node;

    if(counter==1){
        temp->data = value;
        temp->link = NULL;
        head = temp;
    }

    else{
        temp->data = value;
        temp->link = head;
        head = temp;
    }
}

void insertAtEnd(int value){
    counter++;
    Node* temp = new Node;

    if(counter==1){
        temp->data = value;
        temp->link = NULL;
        head = temp;
    }

    else{
        Node* temp1 = head;
        while(temp1->link != NULL){
            temp1 = temp1->link;
        }
        temp->data = value;
        temp->link = NULL;
        temp1->link = temp;
    }
}

void insertAtNthPosition(int value, int n){
     Node* temp = new Node;
     if(n<=counter){
        counter++;

        if(n==1){
            temp->data = value;
            temp->link = head;
            head = temp;
         }
         else{
            Node* temp1 = head;
            for(int i=1; i<n-1; i++){
                temp1 = temp1->link;
            }
            temp->data = value;
            temp->link = temp1->link;
            temp1->link = temp;
         }
     }

     else printf("\n***Insertion in Nth position isn't possible***\n");
}

void deleteNthPosition(int n)
{
   if(n<=counter){
       Node* temp = new Node;

       if(n==1 && counter==1){
            temp = head;
            delete temp;
            head = NULL;
       }

       else if(n==1 && counter!=1){
            temp = head;
            head = temp->link;
            delete temp;
       }

       else if(n==counter){
            Node* temp1 = head;
            for(int i=1; i<n-1; i++){
                temp1 = temp1->link;
            }
            Node* temp2 = temp->link;
            temp1->link = NULL;
            delete temp2;
       }
       else{
            Node* temp1 = head;
            for(int i=1; i<n-1; i++){
                temp1 = temp1->link;
            }
            Node* temp2 = temp1;
            temp1 = temp1->link;
            temp2->link = temp1->link;
            delete temp1;
       }

       counter--;
   }

   else printf("\n***Deletion of Nth position isn't possible***\n");
}


void Print(){
    Node* temp = head;
    printf("List size is %d\nList:", counter);
    if(counter<=0) printf("**List is empty!**\n\n");
    else{
        while(1){
            printf(" %d", temp->data);
            if(temp->link == NULL) break;
            else temp = temp->link;
        }
        printf("\n\n");
    }
}


int main()
{
    insertAtBegin(12);          Print();
    insertAtEnd(24);            Print();
    insertAtBegin(6);           Print();
    insertAtNthPosition(3,1);   Print();
    insertAtEnd(48);            Print();
    insertAtEnd(96);            Print();
    insertAtNthPosition(72,6);  Print();
    insertAtBegin(2);           Print();
    insertAtNthPosition(192,9); Print();
    deleteNthPosition(8);       Print();
    deleteNthPosition(1);       Print();
    deleteNthPosition(3);       Print();

    return 0;
}

