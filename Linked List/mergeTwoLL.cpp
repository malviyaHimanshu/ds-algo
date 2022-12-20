// Merge two sorted linked lists
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

void display(Node * head) {
    while(head) {
        cout<<head->data<<"->";
        head = head->next;
    } cout<<"NULL"<<endl;
}

// Iterative Way
Node * Merge(Node * &head1, Node * &head2) {
    Node *ptr1=head1, *ptr2=head2;
    Node *head3 = new Node(-1);
    Node *ptr3 = head3;

    while(ptr1 && ptr2) {
        if(ptr1->data < ptr2->data) {
            ptr3->next = ptr1;
            ptr1 = ptr1->next;
        } else {
            ptr3->next = ptr2;
            ptr2 = ptr2->next;
        }
        ptr3 = ptr3->next;
    }
    if(ptr1) {
        ptr3->next = ptr1;
    }
    if(ptr2) {
        ptr3->next = ptr2;
    }
    return head3->next;
}

// Recursive Way
Node * MergeRecursive(Node * &head1, Node * &head2) {
    // base case
    if(head1==NULL) {
        return head2;
    }
    if(head2==NULL) {
        return head1;
    }

    // recursive case
    Node * head3;
    if(head1->data < head2->data) {
        head3 = head1;
        head3->next = MergeRecursive(head1->next, head2);
    } else {
        head3 = head2;
        head3->next = MergeRecursive(head1, head2->next);
    }
    return head3;
}

int main() {
    Node * list1 = NULL;
    Node * list2 = NULL;

    push_back(list1, 1);
    push_back(list1, 4);
    push_back(list1, 5);
    push_back(list1, 7);

    push_back(list2, 2);
    push_back(list2, 3);
    push_back(list2, 6);

    display(list1);
    display(list2);

    // display(Merge(list1, list2));
    display(MergeRecursive(list1, list2));

    return 0;
}