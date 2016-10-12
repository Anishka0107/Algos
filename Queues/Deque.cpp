#include <iostream>
using namespace std;

struct Node {
    int info;    
    Node *prev;
    Node *next;
};

class Deque {
    public :
        Node *front;
        Node *back;
        Deque();
        void insertfront();
        void insertback();
        void removefront();
        void removeback();
        void traversequeue();
        void traversestack();
};

Deque :: Deque() {
    front = NULL;
    back = NULL;
}

void Deque :: insertfront() {
    int ele;
    cout << "Enter the element to be inserted : ";
    cin >> ele;
    Node *n = new Node;
    n -> info = ele;
    if (front == NULL) {
        front = n;
        back = n;
        front -> next = back;
        back -> prev = front;
        front -> prev = NULL;
        back -> next = NULL;
        return;
    }
n -> next = front;
front -> prev = n;
n -> prev = NULL;
front = n;
}

void Deque::insertback() {
    int ele;
    cout << "Enter the element to be inserted : ";
    cin >> ele;
    Node *n = new Node;
    n -> info = ele;
    if (front == NULL) {
        front = n;
        back = n;
        front -> next = back;
        back -> prev = front;
        front -> prev = NULL;
        back -> next = NULL;
        return;        
    }
    back -> next = n;
    n -> prev = back;
    n -> next = NULL;
    back = n;    
}

void Deque::removefront() {
    if (front == NULL) {
        cout << "Deque empty dude!!\n";
        return;
    }
    Node *n = front;
    if (front == back) {
        front = NULL;
        back = NULL;
    }
    else {
        front = front -> next;
        front -> prev = NULL;
    }
    cout << "Deleting element " << n -> info << endl;
    delete n;
}

void Deque::removeback() {
    if (back == NULL) {
        cout << "Deque empty dude!!\n";
        return;
    }
    Node *n = back;    
    if (front == back) {
        front = NULL;
        back = NULL;
    }
    else {
        back = back -> prev;
        back -> next = NULL;
    }
    cout << "Deleting element " << n -> info << endl;
    delete n;
}

void Deque::traversequeue() {
    Node *t = front;
    if (t == NULL) {
        cout << "Queue empty dude!!\n";
        return;
    }
    while (t != NULL) {
        cout << t -> info << "  ";
        t = t -> next;
    }
    cout << endl;
}

void Deque::traversestack() {
    Node *t = back;
    if (t == NULL) {
        cout << "Stack empty dude!!\n";
        return;
    }
    while (t != NULL) {
        cout << t -> info << "  ";
        t = t -> prev;
    }
    cout << endl;
}

int main () {
    int x;
    char ch;
    Deque q;
    do {
        cout << "MENU : \n\t1. Insert at front\n\t2. Remove from front\n\t3. Insert at back\n\t4. Remove from back\n\t5. Traverse as a queue\n\t6. Traverse as a stack\nEnter your choice : ";
        cin >> x;
        switch(x) {
            case 1 :
                q.insertfront();
                break;
            case 2 :
                q.removefront();
                break;
            case 3 :
                q.insertback();
                break;
            case 4 :
                q.removeback();
                break;
            case 5 :
                q.traversequeue();
                break;
            case 6 :
                q.traversestack();
                break;
            default :
                cout << "Invalid choice!!";
        }
        cout << "Do you want to continue? ";
        cin >> ch;
    } while (ch == 'y' || ch == 'Y');
    return 0;
}
