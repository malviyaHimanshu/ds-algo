// Reverse a linked list O(N)

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

void display(Node * head) {
    while(head != NULL) {
        cout<<head->data<<" ";
        head = head->next;
    } cout<<endl;
}

// Iterative Way
void reverseLL(Node * &head) {
    Node * prev = NULL;
    Node * current = head;
    Node * next;
    while(current != NULL) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    head = prev;
}

// Recursive Way
Node * reverseLLRecursive(Node * &head) {
    // base case
    if(head==NULL || head->next==NULL) {
        return head;
    }

    Node * newHead = reverseLLRecursive(head->next);
    head->next->next = head;
    head->next = NULL;

    return newHead;
}


int main() {
    Node * head = NULL;
    insertAtTail(head, 1);
    insertAtTail(head, 2);
    insertAtTail(head, 3);
    insertAtTail(head, 4);
    display(head);

    // reverseLL(head);
    Node * newHead = reverseLLRecursive(head);
    display(newHead);

    return 0;
}