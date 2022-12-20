// Circular Linked List
// Last node pointing to the head

#include<iostream>
#pragma GCC optimise("Ofast")
using namespace std;

class Node {
    public:
        int data;
        Node * next;
        Node(int data) {
            this->data = data;
            this->next = NULL;
        }
};

void insertAtHead(Node * &head, int value) {
    Node * newnode = new Node(value);
    if(head==NULL) {
        newnode->next = newnode;
        head = newnode;
        return;
    }
    Node * temp = head;
    while(temp->next != head) {
        temp = temp->next;
    }
    temp->next = newnode;
    newnode->next = head;
    head = newnode;
}

void push_back(Node * &head, int value) {
    if(head==NULL) {
        insertAtHead(head, value);
        return;
    }
    Node * newnode = new Node(value);
    Node * temp = head;
    while(temp->next != head) {
        temp = temp->next;
    }
    temp->next = newnode;
    newnode->next = head;
}

void deleteAtHead(Node * &head) {
    Node * temp = head;
    while(temp->next != head) {
        temp = temp->next;
    }
    Node * todelete = head;
    temp->next = head->next;
    head = head->next;
    delete todelete;
}

void deletion(Node * &head, int pos) {
    Node * temp = head;
    if(pos==1) {
        deleteAtHead(head);
        return;
    }
    int count = 1;
    while(count < pos-1) {
        temp = temp->next;
        count++;
    }
    if(temp->next==head) {
        head = temp->next->next;
    }
    Node * todelete = temp->next;
    temp->next = temp->next->next;
    delete todelete;
}

void display(Node * head) {
    Node * temp = head;
    do {
        cout<<temp->data<<" ";
        temp = temp->next;
    } while(temp!=head);
    cout<<endl;
}


int main() {
    Node * head = NULL;
    push_back(head, 1);
    push_back(head, 2);
    push_back(head, 3);
    push_back(head, 4);
    display(head);

    insertAtHead(head, 5);
    display(head);

    deletion(head, 6);
    display(head);

    return 0;
}