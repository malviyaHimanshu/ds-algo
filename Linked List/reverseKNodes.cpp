// Reverse K nodes in Linked List
// O(N)

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

class LinkedList {
    public:
        Node * head;

        LinkedList() {
            this->head = NULL;
        }

        void push_back(int value);
        void remove(int value);
        void display();
        // reverse k nodes from i to j 
        void reverseKNodes(int start, int end);
};

void LinkedList::push_back(int value) {
    Node * newNode = new Node(value);
    if(head==NULL) {
        head = newNode;
        return;
    }
    Node * temp = this->head;
    while(temp->next) {
        temp = temp->next;
    }
    temp->next = newNode;
}

void LinkedList::remove(int value) {
    if(head == NULL) {
        cout<<"LL is empty"<<endl;
        return;
    }
    Node * temp = this->head;
    while(value != temp->next->data) {
        temp = temp->next;
    }
    Node * deletednode = temp->next;
    temp->next = temp->next->next;
    delete deletednode;
}

void LinkedList::display() {
    Node * head = this->head;
    while(head) {
        cout<<head->data<<"->";
        head = head->next;
    } cout<<"NULL"<<endl;
}

void LinkedList::reverseKNodes(int start, int end) {
    Node *current, *next, *endptr, *startptr=head;
    int i=0;
    while(i<start-1) {
        startptr = startptr->next;
        i++;
    }
    endptr = startptr;
    while(i<end) {
        endptr = endptr->next;
        i++;
    }
    current = startptr->next;
    startptr->next = endptr;
    Node * temp = endptr->next;
    endptr->next = NULL;
    endptr = temp;
    while(current!=NULL) {
        next = current->next;
        current->next = endptr;
        endptr = current;
        current = next;
    }
}

// Reverse K nodes in the linked list 
// (k=2) 1 2 3 4 5 6 -> 2 1 4 3 6 5
Node * revEveryKNodes(Node * &head, int k) {
    Node *prev=NULL, *curr=head, *next;

    int count=0;
    while(curr && count<k) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
        count++;
    }
    
    if(next) {
        head->next = revEveryKNodes(next, k);
    }
    return prev;
}


int main() {
    LinkedList ll;
    ll.push_back(1);
    ll.push_back(2);
    ll.push_back(3);
    ll.push_back(4);
    ll.push_back(5);
    ll.push_back(6);
    ll.display();

    // ll.reverseKNodes(2, 4);
    // ll.display();

    Node * newhead = revEveryKNodes(ll.head, 2);
    ll.head = newhead;
    ll.display();

    return 0;
}