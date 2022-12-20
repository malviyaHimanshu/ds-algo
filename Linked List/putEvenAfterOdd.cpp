// Put even position elements after odd position elements in linked list

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
    Node * newnode = new Node(value);
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

void evenAfterOdd(Node * &head) {
    Node * evenstart = head->next;
    Node * even = evenstart;
    Node * odd = head;

    while(odd->next && even->next) {
        odd->next = even->next;
        odd = odd->next;
        even->next = odd->next;
        even = even->next;
    }
    odd->next = evenstart;
    if(odd->next) {
        even->next = NULL;
    }
}

void display(Node * head) {
    while(head) {
        cout<<head->data<<"->";
        head = head->next;
    } cout<<"NULL"<<endl;
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

    evenAfterOdd(head);
    display(head);

    return 0;
}