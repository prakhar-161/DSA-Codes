#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node *next;
    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
};

Node* deleteFirst(Node* head) {
    if(head == NULL) {
        cout << "Linked List already empty!" <<  endl;
    }
    else {
        Node* temp = head;
        head = head -> next;
        free(temp);
        temp = NULL;
    }
    return head;
}

// two-pointer method
void deleteLast1(Node* head) {
    if(head == NULL) {
        cout << "Linked List is already empty!" << endl;
    }
    else if(head -> next == NULL) {
        delete(head);
        head = NULL;
    }
    else {
        Node* temp = head;
        Node* temp2 = head;
        while(temp -> next != NULL) {
            temp2 = temp;
            temp = temp -> next;
        }
        temp2 -> next = NULL;
        free(temp);
        temp = NULL;
    }
}

// deleting last node using single pointer
void deleteLast2(Node* head) {
    if(head == NULL) {
        cout << "Linked List is already empty!" << endl;
    }
    else if(head -> next == NULL) {
        delete(head);
        head = NULL;
    }
    else {
        Node* temp = head;
        while(temp -> next -> next != NULL) {
            temp = temp -> next;
        }
        free(temp -> next);
        temp -> next = NULL;
    }
}

void deleteNode(Node* &head, int pos) {
    if(pos == 1) {
        Node* temp = head;
        head = head -> next;
        free(temp);
        temp = NULL;
    }
    else {
        // deleting any node or last node
        Node* curr = head;
        Node* prev = NULL;
        
        int cnt = 1;
        
    }
} 

int main() {
    Node* head = deleteFirst(head);
    deleteLast1(head);
    deleteLast1(head);
    Node* ptr = head;

    while(ptr != NULL) {
        cout << ptr -> data << " ";
        ptr = ptr -> next;
    }
    cout << endl;
    return 0;
}