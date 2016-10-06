#include <iostream>
using namespace std;

struct Node {
    int info;
    Node* next;
};

void bubblesort (int *arr, int n) {
	for (int i = 0; i < n-1; i++) {
		for (int j = 0; j < n-i-1; j++) {
			if (arr[j] > arr[j+1]) {
				int temp = arr[j];
				arr[j] = arr[j+1];
				arr[j+1] = temp;
			}
		}
	}
}

Node* sort (Node* start) {
    Node* sortstarter = new Node;
    Node *curr = sortstarter;
    Node *ptr = start;
    int count = -1;
    while (ptr != NULL) {
        count++;
        ptr = ptr -> next;
    }
    ptr = start;
    int arr[count], i=0;
    while (ptr != NULL) {
        arr[i] = ptr -> info;
        i++;
        ptr = ptr -> next;
    }
    bubblesort (arr, count);
    for (i = 0; i < count-1; i++) {
        curr -> info = arr[i];
        curr -> next = new Node;
        curr = curr -> next; 
    }
    curr -> info = arr[count-1];
    curr -> next = NULL;
    return sortstarter;
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
    start = sort(start);
    cout << "\nThe linked list after sorting is : ";
    trav = start;
    while (trav != NULL){
        cout << trav -> info << "  ";
        trav = trav -> next;
    } 
    return 0;
}