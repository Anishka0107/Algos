#include <iostream>
using namespace std; 

struct Node {
    int info;
    Node *next;    
};

Node* reverse (Node *start) {
    Node *temp = start -> next;
    Node *curr = start -> next;
    Node *prev = start;
    start -> next = NULL;
    while(temp -> next != NULL){
        temp = temp -> next;
        curr -> next = prev;
        prev = curr;
        curr = temp;                         
    }
    temp -> next = prev;
    return temp -> next;
}

int main() {
    Node *start = new Node;
    char ch;
    Node *prev = start;
    do {
        int ele;
        cout << "Enter the element to be inserted in the linked list : ";
        cin >> ele;
        prev -> next = new Node; 
        prev -> info = ele;
        prev = prev -> next;
        prev -> next = NULL;
        cout << "Do you want to enter more elements? ";
        cin >> ch;
    } while (ch == 'Y' || ch == 'y');
    cout << "The original linked list is : ";
    Node *trav = start;
    while (trav -> next != NULL){
        cout << trav -> info << "  ";
        trav = trav -> next;
    }     
    start = reverse(start);
    cout << "\nThe linked list after reversal is : ";
    trav = start;
    while (trav != NULL){
        cout << trav -> info << "  ";
        trav = trav -> next;
    } 
    return 0;
}