#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Max Heap Implementation
// Useful in Priority Queues

class Heap {
    private :
        vector<int> h;
    public :
        int parent(int);
        int lc(int);
        int rc(int);
        void maxHeapify(int);
        void insert(int);
        void remove(int);
        void printHeap();
};

int Heap :: parent ( int idx ) {
    if ( idx == 0 ) {
        return -1;  // invalid - no parent of root
    }
    return (idx-1)/2;
}

int Heap :: lc ( int idx ) {
    if ( 2*idx+1 >= h.size() ) {
        return -1;       // invalid - no child of leaf node
    }
    return (2*idx+1);
}

int Heap :: rc ( int idx ) {
    if ( 2*idx+2 >= h.size() ) {
        return -1;       // invalid - no child of leaf node
    }
    return (2*idx+2);
}

void Heap :: insert ( int ele ) {
    h.push_back(ele);
    int id = h.size() - 1;
    while ( id > 0 && h[id] > h[parent(id)] ) {
        swap (h[id], h[parent(id)]);
        id = parent(id);
    }
}

void Heap :: maxHeapify ( int k ) {
    int l = lc(k);
    int r = rc(k);
    int large = k;
    if ( l >= 0 && h[l] > h[large] ) {
        large = l;
    }
    if ( r >= 0 && h[r] > h[large] ) {
        large = r;
    }
    if ( large != k ){
        swap (h[k], h[large]);
        maxHeapify (large);
    }
}

void Heap :: remove ( int ele ) {
    auto it = find(h.begin(), h.end(), ele);
    if ( it == h.end() ) {
        cout << "Element not found in heap!!\n";
    }
    else {
        h.erase(it);
        maxHeapify(0);
    }
}

void Heap :: printHeap() {             // level order traversal of heap
    int ctr = 0;
    int mul = 2;
    while ( ctr < h.size() ) {
        while ( ctr < mul-1 && ctr < h.size() ) { 
            cout << h[ctr] << " ";
            ctr++;
        } 
        mul *= 2;
        cout << endl;
    }
}

int main() {
    Heap heap;
    int ch;
    char c = 'y';
    cout << "MENU\n1. Insert\n2. Delete\n3. Print the Heap\n";
    while ( c == 'y' || c == 'Y' ) {
        cout << "Enter your choice : ";
        cin >> ch;
        int ele;
        switch (ch) {
            case 1 :
                cout << "Enter the element to be inserted : ";
                cin >> ele;
                heap.insert (ele);
                break;
            case 2 :
                cout << "Enter the element to be deleted : ";
                cin >> ele;
                heap.remove (ele);
                break;
            case 3 :
                cout << "The heap is :\n";
                heap.printHeap();
                break;
            default :
                cout << "Wrong choice entered!!\n";
        }
        cout << "Do you wish to continue : ";
        cin >> c;
    }
    return 0;
}
