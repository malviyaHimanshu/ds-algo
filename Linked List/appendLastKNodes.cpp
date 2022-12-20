// Append last k nodes to start of the linked list

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

void push_back(Node * &head, int value) {
    Node  * newnode = new Node(value);
    if(head==NULL) {
        head = newnode;
        return;
    }
    Node * temp = head;
    while(temp->next) {
        temp = temp->next;
    }
    temp->next = newnode;
}

void display(Node * head) {
    while(head) {
        cout<<head->data<<"->";
        head = head->next;
    } cout<<"NULL"<<endl;
}

void appendLastKNode(Node * &head, int k) {
    Node * temp = head;
    int len = 0;
    while(temp) {
        len++;
        temp = temp->next;
    }
    
    Node *newtail, *newhead, *tail=head;
    k = k%len;
    if(k==0) {
        return;
    }
    int count=1;
    while(tail->next) {
        if(count==len-k) {
            newtail = tail;
            newhead = tail->next;
        }
        tail = tail->next;
        count++;
    }

    newtail->next = NULL;
    tail->next = head;
    head = newhead;
}

int main() {
    Node * head = NULL;
    push_back(head, 1);
    push_back(head, 2);
    push_back(head, 3);
    push_back(head, 4);
    push_back(head, 5);
    push_back(head, 6);
    display(head);

    appendLastKNode(head, 6);
    display(head);

    return 0;
}