#include <iostream>
#define SIZE 1000
using namespace std;

struct Node {
    public :
    int data;
    int key;
};

Node* hashtable[SIZE] = {NULL};
int value;      // a global variable to save the data of previously searched / currently being searched for key

int truncationhash (int key) {
    return key % 100;        // retrieving the last two digits 
}

int foldinghash (int key) {
    int part1, part2, part3;
    part1 = key % 10;
    key /= 10;
    part2 = key %1000;
    key /= 1000;
    part3 = key %100;
    key /= 100;
    part1 = part1 + part2 + part3;     // reusing part1 to store the sum of the three parts, basically combining the parts
    return truncationhash (part1);     // now folding the combination, using tructaion hashing function
}

//linear probing
void insert (int key, int data) {
    Node *n = new Node;
    n -> data = data;
    n -> key = key;
    int h = foldinghash (key);
    if (hashtable[h] == NULL) {    // if the index is empty
        hashtable[h] = n;
    }
    else {
        for (int i = h+1; i < SIZE; i++) {
            if (hashtable[i] == NULL) {
                hashtable[i] = n;
                return;
            }
        }
        for (int i = 0; i < h; i++) {
            if (hashtable[i] == NULL) {
                hashtable[i] = n;
                return;
            }
        }
        cout << "Sorry! Hash table full...\n";
    }
}

int search (int key) {
    int pos = foldinghash (key);
    if (hashtable[pos] == NULL)
        return -1;
    for (int i = pos; i < SIZE; i++) {
        if (hashtable[i] != NULL && hashtable[i] -> key == key) {
            value = hashtable[i] -> data;
            return 0;
        }
    }
    for (int i = 0; i < pos; i++) {
        if (hashtable[i] != NULL && hashtable[i] -> key == key) {
            value = hashtable[i] -> data;
            return 0;
        }        
    }
    return -1;
}
// for quadratic probing, comment the insert and search functions and uncomment the code below :
/*
bool isvisitorvisited(int arr[]) {
    for (int i = 0; i < SIZE; i ++) {
        if (arr[i] == 0)
            return false;
    }
    return true;
}

void insert (int key, int data) {
    Node *n = new Node;
    n -> data = data;
    n -> key = key;
    int visitor[SIZE] = {0};
    int h = foldinghash (key);
    if (hashtable[h] == NULL) {    // if the index is empty
        hashtable[h] = n;
    }
    else {
        int i, quad = 0, no = 0;       // no is just a variable to keep the number of attempts made in order to search for an empty location
        for (i = h; no < SIZE; i += quad*quad) {           // the idea is to linearly probe for an empty location through the non visited nodes after a custom limit is crossed
            cout << "current value of i is"<<i<<endl;      // after a limit, we need to search linearly for smaller sizes
            if (isvisitorvisited (visitor))                // for reducing time, ditch the fact that it looks ugly 
                break;
            visitor[i] = 1;    
            if (hashtable[i] == NULL) {
                hashtable[i] = n;
                return;
            }
            quad++;
            if (i + quad*quad >= SIZE) {
                i = (i + quad*quad) % SIZE;
                i -= quad*quad;
            }
            no++;
        }
        for (i = 0; i < SIZE; i++) {
            if (hashtable[i] == NULL) {
                hashtable[i] = n;
                return;
            }            
        }
        cout << "Sorry! Hash table full...\n";
    }
}

int search (int key) {
    int pos = foldinghash (key);
    if (hashtable[pos] == NULL)
        return -1;
    if (hashtable[pos] -> key == key) {
        value = hashtable[pos] -> data;
        return 0;
    }
    int visitor[SIZE] = {0};
    int quad = 0, i, no = 0 ;
    for (i = pos; no < SIZE; i += quad*quad) {
        if (isvisitorvisited (visitor))
            break;
        visitor[i] = 1;    
        if (hashtable[i] -> key == key) {
            value = hashtable[i] -> data;
            return 0;
        }
        quad++;
        if (i + quad*quad >= SIZE) {
            i = (i + quad*quad) % SIZE;
            i -= quad*quad;
        }
        no++;
    }
    for (i = 0; i < SIZE; i++) {
        if (hashtable[i] -> key == key) {
            value = hashtable[i] -> data;
            return 0;
        }            
    }    
    return -1;
}
*/

// Double hashing
/* A simple and cool double hash is :
h1 = key % 10;
h2 = 7 - (key % 7)
There can be many others!!!
*/

// ViciousDragonAnishka, remember to try out various other security related hashing functions and also those provided by IDEs (very fast and very low collision tendency)

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