#include <iostream>
using namespace std;

class Node {
    public :
        int info;    
        Node *prev;
        Node *next;
        Node();
};

Node :: Node() {
    prev = NULL;
    next = NULL;
}

class PriorityQueue {
    public :
        Node *front;
        Node *rear;
        PriorityQueue();
        void enqueue();
        void dequeue();
        void traverse();
};

PriorityQueue :: PriorityQueue() {
    front = NULL;
    rear = NULL;
}

void PriorityQueue :: enqueue() {
    int ele;
    cout << "Enter the new element : ";
    cin >> ele;
    Node *n = new Node;
    n -> info = ele;
    if (front == NULL) {
        front = n;
        rear = n;
        return;
    }
    Node *curr = front;
    if (ele < curr -> info) {
        n -> next = front;
        n -> prev = NULL;
        front -> prev = n;
        front = n;
        return;
    }
    while (ele >= curr -> info && curr -> next != NULL) 
        curr = curr -> next;
    if (curr -> next != NULL) {
        curr -> prev -> next = n;
        n -> prev = curr -> prev;
        curr -> prev = n;
        n -> next = curr;
    }
    else if (curr -> info < ele) {
        n -> next = NULL;
        n -> prev = rear;
        rear -> next = n;
        rear = n;        
    }
    else {
        curr -> prev -> next = n;
        n -> prev = curr -> prev;
        n -> next = curr;
        curr -> prev = n;
    }
}

void PriorityQueue :: dequeue() {
    if (front == NULL) {
        cout << "Queue empty!!\n";
        return;
    }
    Node *n = front;
    if (front == rear) {
        int ele = n -> info;
        delete n;
        cout << "Deleted element " << ele << endl;
        front = NULL;
        rear = NULL;
        return;
    }
    front -> next -> prev = NULL;
    front = front -> next;
    int ele = n -> info;
    delete n;
    cout << "Deleted element " << ele << endl;
}

void PriorityQueue :: traverse() {
    Node *curr = front;
    if (curr == NULL) {
        cout << "Queue empty!\n";
        return;
    }
    while (curr != NULL) {
        cout << curr -> info << "  ";
        curr = curr -> next;
    }
    cout << endl;
}

int main () {
    int x;
    char ch;
    PriorityQueue q;
    do {
        cout << "MENU : \n\t1. Insert an element\n\t2. Remove an element\n\t3. Traverse the priority queue\nEnter your choice : ";
        cin >> x;
        switch(x) {
            case 1 :
                q.enqueue();
                break;
            case 2 :
                q.dequeue();
                break;
            case 3 :
                q.traverse();
                break;
            default :
                cout << "Invalid choice!!\n";
        }
        cout << "Do you want to continue? ";
        cin >> ch;
    } while (ch == 'y' || ch == 'Y');
    return 0;
}