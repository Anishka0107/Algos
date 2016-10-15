#include <iostream>
#define SIZE 10
#define ovSIZE 100
using namespace std;

// efficiency of hashing is O(1) 
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

Node* mainhashtable[SIZE] = {NULL};
Node* overflowarea[ovSIZE] = {NULL};   //one major disadvantage of coalesced chaining collision resolution is the fixing of sizes 
int value;

int midsquarehash (int key) {       // the hashing function
    key = key * key;                // assuming each key to be a >= 5 digit number, this can be changed as well    
    key = key / 100;
    key = key % 10;                 // we have finally extracted the third digit of the squared key
    return key;
}

void insert (int key, int data) {
    Node* n = new Node;
    n -> data = data;
    n -> key = key;
    int h = midsquarehash (key);
    if (mainhashtable[h] == NULL) {   //no entry is present at this position initially
        mainhashtable[h] = n;
    }
    else {   // as an entry is already present we need to create a linked list
        Node *t = mainhashtable[h];
        while (t -> link != NULL) {
            t = t -> link;
        }
        for (int i = 0; i < ovSIZE; i ++) {
            if (overflowarea[i] == NULL) {
                overflowarea[i] = n;
                t -> link = overflowarea[i];
                return;
            }
        }
        cout << "No more space left dude!!\n";
    }
}

int search (int key) {
    int pos = midsquarehash (key);
    if (mainhashtable[pos] == NULL) {
        return -1;
    }
    Node *n = mainhashtable[pos];
    if (key == n -> key) {      // searching in main table
        value = n -> data;
        return 0;
    }
    n = n -> link;
    while (n != NULL) {      // searching in overflow area, separated out for ease
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