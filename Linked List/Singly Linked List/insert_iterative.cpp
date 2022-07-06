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

void insertAtFront(Node *&head, int x) {
    Node *newNode = new Node(x);
    if (head == NULL)
    {
        head = newNode;
    }
    else
    {
        newNode->next = head;
        head = newNode;
    }
}

void insertAtTail(Node *&head, int x) {
    Node *newNode = new Node(x);
    newNode->next = NULL;
    Node *temp = head;

    while (temp->next != NULL)
    {
        temp = temp->next;
    }

    temp->next = newNode;
    temp = newNode;
}

Node *insertAtPosition(Node *head, int i, int x)
{
    Node *newNode = new Node(x);
    newNode->next = NULL;
    Node *temp = head;
    int count = 0;

    if (i == 0)
    {
        newNode->next = head;
        head = newNode;
        return head;
    }

    while (temp != NULL && count < i - 1)
    {
        temp = temp->next;
        count++;
    }

    if (temp != NULL)
    {
        newNode->next = temp->next;
        temp->next = newNode;
    }
    return head;
}

void print(Node *&head) {
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main() {
    Node *node1 = new Node(2);
    // cout << node1 -> data << endl;
    // cout << node1 -> next << endl;

    Node *head = node1;

    insertAtFront(head, 1);
    insertAtTail(head, 3);
    insertAtTail(head, 4);
    print(head);                // 20 10 30 40

    head = insertAtPosition(head, 0, 9);
    // print(head);

    head = insertAtPosition(head, 3, 5);
    print(head);

    return 0;
}