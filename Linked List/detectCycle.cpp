// Detect and Remove Cycle in a Linked List 
// Floyd's Algo or Hare and tortoise algo

/*
    Detection and Removal of Cycle
    - Floyd's algo says that for detecting a cycle use two pointers one fast and one slow
    slow pointer will take 1 step and fast will take 2. Keep them running till they meet at a position
    if they meet at a position then that means cycle exists.

    Now, how to remove this cycle?
    - The point where both the pointers met get back one of the pointers let's say fast to head
    and then start both the pointer with one step (fast starts from head and slow start from meeting point).
    ** Now they will meet at the point where the cycle started **
    So keep on checking fast->next == slow->next
        and if its true at any point make slow->next = NULL and Boom, you got rid of cycle.
*/

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
        void makeCycle(int pos);
        bool detectCycle();
        void removeCycle();
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

void LinkedList::makeCycle(int pos) {
    Node * temp = head;
    Node * startNode;
    int count=1;
    while(temp->next) {
        if(count==pos) {
            startNode = temp;
        }
        temp = temp->next;
        count++;
    }
    temp->next = startNode;
}

bool LinkedList::detectCycle() {
    Node *slow = head, *fast = head;
    while(fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
        if(fast==slow) {
            return true;
        }
    }
    return false;
}

void LinkedList::removeCycle() {
    Node *slow = head, *fast = head;
    do {
        slow = slow->next;
        fast = fast->next->next;
    } while(slow!=fast);

    fast = head;
    while(slow->next != fast->next) {
        slow = slow->next;
        fast = fast->next;
    }
    slow->next = NULL;
}

int main() {
    LinkedList ll;
    ll.push_back(1);
    ll.push_back(2);
    ll.push_back(3);
    ll.push_back(4);
    ll.push_back(5);
    ll.push_back(6);
    ll.makeCycle(3);

    cout<<ll.detectCycle()<<endl;

    return 0;
}