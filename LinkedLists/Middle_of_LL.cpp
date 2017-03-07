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

Node* man_in_the_middle (Node* start) {
    Node *mid = start, *end = start;
    while (end != NULL && end -> next != NULL) {
        mid = mid -> next;
        end = end -> next -> next;
    }
    return mid;
}

int main() {
    Node* start = new Node(10);
    start -> next = new Node(20);
    start -> next -> next = new Node(30);
    start -> next -> next -> next = new Node(40);
    start -> next -> next -> next -> next = new Node(50);
    cout << "The middle of the linked list is : " << man_in_the_middle(start) -> info;
    start -> next -> next -> next -> next -> next = new Node(60);
    cout << "\nNow the middle element is : " << man_in_the_middle(start) -> info;
    return 0;
}
