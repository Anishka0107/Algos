#include <iostream>
using namespace std;

class Node {
    public:
        int info;
        Node* next;
        Node (int info) {
            this -> info = info;
            next = NULL;
        }
};

Node* find_cycle (Node* start) {
    Node *ptr1 = start, *ptr2 = start -> next;    
    while (ptr2 != NULL && ptr2 -> next != NULL) {
        ptr1 = ptr1 -> next;
        ptr2 = ptr2 -> next -> next;
        if (ptr1 == ptr2) {
            return ptr1;
        }
    }
    return NULL;
}

void eliminate_cycle (Node* start) {
    if ( !find_cycle (start)) {
        cout << "No cycle to be eliminated!\n";
        return;
    }
    Node *ptr1 = start, *ptr2 = find_cycle(start);
    while (ptr1 != ptr2 -> next) {
        ptr1 = ptr1 -> next;
        ptr2 = ptr2 -> next;
    }
    ptr2 -> next = NULL;
    cout << "Cycle eliminated!\n";
}

int main() {
    Node* start = new Node(10);
    start -> next = new Node(20);
    start -> next -> next = new Node(30);
    start -> next -> next -> next = new Node(40);
    start -> next -> next -> next -> next = new Node(50);
    start -> next -> next -> next -> next -> next = new Node(60);
    start -> next -> next -> next -> next -> next -> next = start -> next -> next;   // cycle
    cout << "The linked list is : ";
    int ctr = 0;
    for (Node* i = start; i != NULL && ctr < 20; i = i -> next, ctr++ ) {         // ctr introduced to avoid infinite loop
        cout << i -> info << " ";
    }
    if (find_cycle (start)) {
        cout << "...\nCycle exists in the linked list!\n";
    }
    else {
        cout << "No cycles exist in the linked list!\n";
    }
    eliminate_cycle (start);
    find_cycle (start);
    if (find_cycle (start)) {
        cout << "Cycle exists in the linked list!\n";
    }
    else {
        cout << "No cycles exist in the linked list!\n";
    }
    eliminate_cycle (start);
    cout << "Now the linked list is : ";
    for (Node* i = start; i != NULL; i = i -> next) {
        cout << i -> info << " ";
    }
    return 0;
}
