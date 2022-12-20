// Find the intersection point of two linked list
// O(max(len1, len2))

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
        
        // bool operator==(Node &rhs) {
        //     return data == rhs.data;
        // }
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

int getLength(Node * head) {
    int len=0;
    while(head) {
        head = head->next;
        len++;
    }
    return len;
}

int findIntersection(Node * head1, Node * head2) {
    int len1 = getLength(head1);
    int len2 = getLength(head2);
    Node *ptr1=head1, *ptr2=head2;
    if(len1 > len2) {
        int i=0;
        while(i < len1-len2 && ptr1) {
            i++;
            ptr1 = ptr1->next;
        }
    } else {
        int i=0;
        while(i < len2-len1 && ptr2) {
            i++;
            ptr2 = ptr2->next;
        }
    }

    while(ptr1 && ptr2) {
        if(ptr1==ptr2) {
            return ptr1->data;
        }
        ptr1 = ptr1->next;
        ptr2 = ptr2->next;
    }
    return -1;
}

void intersect(Node * &head1, Node * &head2, int pos) {
    Node * temp1 = head1;
    Node * temp2 = head2;
    pos--;
    while(pos--) {
        temp1 = temp1->next;
    }
    while(temp2->next) {
        temp2 = temp2->next;
    }
    temp2->next = temp1;
}

int main() {
    Node * head1 = NULL;
    Node * head2 = NULL;

    push_back(head1, 1);
    push_back(head1, 2);
    push_back(head1, 3);
    push_back(head1, 4);
    push_back(head1, 5);
    push_back(head1, 6);

    push_back(head2, 9);
    push_back(head2, 10);
    intersect(head1, head2, 5);

    display(head1);
    display(head2);
    cout<<findIntersection(head1, head2)<<endl;

    return 0;
}
