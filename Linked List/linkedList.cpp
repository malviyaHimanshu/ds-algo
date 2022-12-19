/*
    Limitations in arrays
    - Fixed size
    - contiguous block of memory
    - insertion and deletion is costly
*/

/*
    Linked List
    - size can be modified
    - non contiguous memory
    - insertion and deletion at any point is easier

    NODE : [ data | next ]
    data : value
    next : address of next node
*/

#include<iostream>
#pragma GCC optimise("Ofast")
using namespace std;

class Node {
    public:
        int data;
        Node *next;

        Node(int data) {
            this->data = data;
            this->next = NULL;
        }
};

void insertAtTail(Node * &head, int value) {
    Node * newNode = new Node(value);
    if(head==NULL) {
        head = newNode;
        return;
    }

    Node * temp = head;
    while(temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
}

void insertAtHead(Node * &head, int value) {
    Node * newNode = new Node(value);
    newNode->next = head;
    head = newNode;
}

bool search(Node * head, int key) {
    while(head != NULL) {
        if(key == head->data) return true;
        head = head->next;
    } return false;
}

void deleteAtHead(Node * &head) {
    Node * todelete = head;
    head = head->next;
    delete todelete;
}

void deletionByValue(Node * &head, int value) {
    if(search(head, value)) {
        if(head == NULL) {
            cout<<"List is empty"<<endl;
            return;
        }
        
        if(head->next == NULL) {
            deleteAtHead(head);
            return;
        }

        Node * temp = head;
        while(temp->next->data != value) {
            temp = temp->next;
        }
        Node * todelete = temp->next;
        temp->next = temp->next->next;
        delete todelete;
        return;
    } else {
        cout<<"Node NOT found"<<endl;
    }
}

void display(Node * head) {
    while(head != NULL) {
        cout<<head->data<<" ";
        head = head->next;
    } cout<<endl;
}

int main() {
    Node * head = NULL;
    insertAtTail(head, 1);
    insertAtTail(head, 2);
    insertAtTail(head, 3);
    insertAtTail(head, 4);

    insertAtHead(head, 7);
    display(head);

    deletionByValue(head, 4);
    display(head);

    deleteAtHead(head);
    display(head);

    return 0;
}



