#include <iostream>

using namespace std;

struct Node {
    int info;
    Node *next;    
};

Node* merge (Node* l1, Node* l2) {
    Node *start = new Node;
    Node *curr = start;
    while (l1 -> next != NULL && l2 -> next != NULL) {
        if (l1 -> info > l2 -> info) {
            curr -> info = l2 -> info;
            l2 = l2 -> next;
        }
        else {
            curr -> info = l1 -> info;
            l1 = l1 -> next;
        }
            curr -> next = new Node;
            curr = curr -> next;
    }
    if ((l1 -> next == NULL) && (l2 -> next == NULL)) {
        curr -> next = NULL;
        return start;
    }
    while (l1 -> next != NULL) {
        curr -> info = l1 -> info;
        curr -> next = new Node;
        curr = curr -> next;
        l1 = l1 -> next;
    }
    while (l2 -> next != NULL) {
        curr -> info = l2 -> info;
        curr -> next = new Node;
        curr = curr -> next;
        l2 = l2 -> next;
    }
    curr -> next = NULL;        
    return start;
}

int main() {
    cout << "Please be careful enough to enter the two linked lists in sorted order for merging to be accurate!\n";
    Node *start1 = new Node;
    Node *start2 = new Node;
    char ch;
    Node *prev = start1;
    do {
        int ele;
        cout << "Enter the element to be inserted in the first linked list : ";
        cin >> ele;
        prev -> next = new Node; 
        prev -> info = ele;
        prev = prev -> next;
        prev -> next = NULL;
        cout << "Do you want to enter more elements? ";
        cin >> ch;
    } while (ch == 'Y' || ch == 'y');
    cout << "The first linked list is : ";
    Node *trav = start1;
    while (trav -> next != NULL) {
        cout << trav -> info << "  ";
        trav = trav -> next;
    }
    cout << endl;
    Node* prevx = start2;
    do {
        int ele;
        cout << "Enter the element to be inserted in the second linked list : ";
        cin >> ele;
        prevx -> next = new Node; 
        prevx -> info = ele;
        prevx = prevx -> next;
        prevx -> next = NULL;
        cout << "Do you want to enter more elements? ";
        cin >> ch;
    } while (ch == 'Y' || ch == 'y');
    cout << "The second linked list is : ";
    Node* travx = start2;
    while (travx -> next != NULL){
        cout << travx -> info << "  ";
        travx = travx -> next;
    }
    cout << endl;
    cout << "The merged linked list is : ";
    Node* travr = merge (start1, start2);;
    while (travr -> next != NULL) {
        cout << travr -> info << "  ";
        travr = travr -> next;
    }
    return 0;
}