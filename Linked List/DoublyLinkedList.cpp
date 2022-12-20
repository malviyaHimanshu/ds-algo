// Doubly Linked List
// Node Structure : [ prev | data | next ]

#include<iostream>
#pragma GCC optimise("Ofast")
using namespace std;

class Node {
    public:
        int data;
        Node *prev, *next;
        Node(int data) {
            this->data = data;
            this->prev = NULL;
            this->next = NULL;
        }
};

class DoublyLL {
    public:
        Node * head;
        DoublyLL() {
            this->head = NULL;
        }

        void push_back(int value) {
            Node * newNode = new Node(value);
            if(head == NULL) {
                head = newNode; 
                return;
            }
            Node * temp = head;
            while(temp->next) {
                temp = temp->next;
            }
            temp->next = newNode;
            newNode->prev = temp;
        }

        void insertAtHead(int value) {
            Node * newNode = new Node(value);
            if(head == NULL) {
                head = newNode;
                return;
            }
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }

        void deletion(int pos) {
            if(!head) {
                cout<<"LL is empty"<<endl;
                return;
            }
            Node * temp = head;
            int count=1;
            while(temp && count < pos) {
                temp = temp->next;
                count++;
            }
            if(temp==NULL) {
                cout<<"[ERROR] : Index out of bound"<<endl;
                return;
            }
            Node * todelete = temp;
            if(temp->next!=NULL) {
                temp->next->prev = temp->prev;
            }
            if(temp->prev!=NULL) {
                temp->prev->next = temp->next;
            } else { // deleting the first node
                head = temp->next;
            }
            delete todelete;
        }

        void display() {
            Node * temp = head;
            while(temp) {
                cout<<temp->data<<" ";
                temp = temp->next;
            } cout<<endl;
        }
};

int main() {
    DoublyLL ll;
    ll.push_back(1);
    ll.push_back(2);
    ll.push_back(3);
    ll.push_back(4);
    ll.insertAtHead(5);
    ll.display();

    ll.deletion(3);
    ll.display();

    return 0;
}