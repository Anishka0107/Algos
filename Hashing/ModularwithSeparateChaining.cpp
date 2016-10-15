#include <iostream>
#define SIZE 11
using namespace std;

class Node {
    public :
    int data;
    int key;
    Node *link;
    Node() {
        data = 0;
        key = -1;
        link = NULL;
    }
};

Node* hashtable[SIZE] = {NULL};
int value;

int modularhash (int key) {       // the hashing function
    return key % SIZE;
}

void insert (int key, int data) {
    Node* n = new Node;
    n -> data = data;
    n -> key = key;
    int h = modularhash (key);
    if (hashtable[h] == NULL) {   //no entry is present at this position initially
        hashtable[h] = n;
    }
    else {   // as an entry is already present we need to create a linked list
        Node *t = hashtable[h];
        while (t -> link != NULL) {
            t = t -> link;
        }
        t -> link = n;
    }
}

int search (int key) {
    int pos = modularhash (key);
    if (hashtable[pos] == NULL)
        return -1;
    Node *n = hashtable[pos];
    while (n != NULL) {
        if (key == n -> key) {
            value = n -> data;
            return 0;
        }
        n = n -> link;
    }
    return -1;
}

int main() {
    int x;
    char ch = 'Y';
    while (ch != 'N' && ch != 'n') {
        cout << "Do you want to insert an element or search for an element? (1 or 2) : ";
        cin >> x;
        if (x == 1) {
            int key, data;
            cout << "Enter the key and the data of the element you want to insert : ";
            cin >> key >> data;
            insert (key, data);
        }
        else if (x == 2) {
            int key;
            cout << "Enter the key of the element you wish to search for : ";
            cin >> key;
            int res = search (key);
            if (res == -1) {
                cout << "Sorry! Element not found!\n";
            }
            else {
                cout << "Element found! The data stored is : " << value << endl;
            }
        }
        else {
            cout << "Invalid choice!\n";
        }
        cout << "Want to continue? ";
        cin >> ch;
    }
    return 0;
}
