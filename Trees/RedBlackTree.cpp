#include <bits/stdc++.h>
using namespace std;

enum colour {
    RED, BLACK
};

class Node {
    public:
        int info;
        colour c;
        Node* parent;
        Node* lc;
        Node* rc;
        Node (int info) {
            this -> info = info;
            c = RED;
            parent = NULL;
            lc = NULL;
            rc = NULL;
        }
};

class RedBlackTree {
    public:
        Node* root;
        RedBlackTree() {
            root = NULL;
        }
        void insert(int);
        void remove(int);
        void level_order_traversal();
        void rotate_left(Node*);
        void rotate_right(Node*);
        void fix(Node*);
};

void RedBlackTree :: insert (int ele) {
    Node* n = new Node (ele);
    if (root == NULL) {
        root = n;
        root -> c = BLACK;
        return;
    }
    Node* par = NULL;
    Node* curr = root;
    while (curr != NULL) {
        par = curr;
        if (ele < curr -> info) 
            curr = curr -> lc;
        else if (ele > curr -> info) 
            curr = curr -> rc;
        else {
            cout << "Similar elements cannot be inserted!\n";
            return;
        }
    }
    if (ele < par -> info)
        par -> lc = n;
    else
        par -> rc = n;
    n -> parent = par;
    fix (n);
}

void RedBlackTree :: remove (int ele) {

}

void RedBlackTree :: level_order_traversal() {
    if (root == NULL) {
        cout << "The tree is empty!\n";
        return;
    }
    queue<Node*> q;
    q.push(root);
    while (!q.empty()) {
        Node* curr = q.front();
        cout << curr -> info << " ";
        q.pop();
        if (curr -> lc != NULL) 
            q.push (curr -> lc);
        if (curr -> rc != NULL) 
            q.push (curr -> rc);
    }
    cout << "\n";
}

void RedBlackTree :: rotate_left (Node* curr_root) {
    Node* aux = curr_root -> rc;
    curr_root -> rc = aux -> lc;
    aux -> lc -> parent = curr_root;
    aux -> parent = curr_root -> parent;
    if (curr_root -> parent == NULL) 
        root = aux;
    else if (curr_root -> parent -> lc == curr_root)
        curr_root -> parent -> lc = aux;
    else
        curr_root -> parent -> rc = aux;
    aux -> lc = curr_root;
    curr_root -> parent = aux;
}

void RedBlackTree :: rotate_right (Node* curr_root) {
    Node* aux = curr_root -> lc;
    curr_root -> lc = aux -> rc;
    aux -> rc -> parent = curr_root;
    aux -> parent = curr_root -> parent;
    if (curr_root -> parent == NULL) 
        root = aux;
    else if (curr_root -> parent -> lc == curr_root)
        curr_root -> parent -> lc = aux;
    else
        curr_root -> parent -> rc = aux;
    aux -> rc = curr_root;
    curr_root -> parent = aux;
}

void RedBlackTree :: fix (Node* n) {
    while ((n != root) && (n -> c == RED) && (n -> parent -> c == RED)) {
        if (n -> parent == n -> parent -> parent -> lc) {         // parent is left child of grandparent
            Node* _uncle = n -> parent -> parent -> rc;
            if (_uncle != NULL && _uncle -> c == RED) {         // the uncle of the new node is RED, so only recolouring
                n -> parent -> parent -> c = RED;
                n -> parent -> c = BLACK;
                _uncle -> c = BLACK;
                n = n -> parent -> parent;
            }
            else {                           // the uncle of the new node is BLACK, so rotation and recolouring
                if (n == n -> parent -> rc) {           // left right case
                    n = n -> parent; 
                    rotate_left (n);
                }
                // left left case, also the code segment to be followed up by right left case
                n -> parent -> c = RED;
                n -> parent -> parent -> c = BLACK;
                rotate_right (n -> parent -> parent);
            }
        }
        else {          // parent is right child of grandparent
            Node* _uncle = n -> parent -> parent -> lc;
            if (_uncle != NULL && _uncle -> c == RED) {      // the uncle of the new node is RED, so only recolouring
                n -> parent -> parent -> c = RED;
                n -> parent -> c = BLACK;
                _uncle -> c = BLACK;
                n = n -> parent -> parent;
            }
            else {                                   // the uncle of the new node is BLACK, so rotation and recolouring
                if (n == n -> parent -> lc) {           // right left case
                    n = n -> parent;
                    rotate_right (n);
                }
                // right right case, also the code segment to be followed up by left right case
                n -> parent -> c = RED;
                n -> parent -> parent -> c = BLACK;
                rotate_left (n -> parent -> parent);
            }
        }
    }
    root -> c = BLACK;
}

int main() {
    RedBlackTree rbt;
    cout << "MENU\n\t1. Insert\n\t2. Remove\n\t3. Traverse\n\t4. Exit\n";
    int ch;
    while (true) {
        cout << "Enter your choice : ";
        cin >> ch;
        int ele;
        switch (ch) {
            case 1:
                cout << "Enter the element to be inserted : ";
                cin >> ele;
                rbt.insert(ele);
                break;
            case 2:
                cout << "Enter the element to be removed : ";
                cin >> ele;
                rbt.remove(ele);
                break;
            case 3:
                cout << "The level order traversal of the red black tree is : ";
                rbt.level_order_traversal();
                break;
            case 4:
                exit(1);
            default:
                cout << "Wrong choice entered!\n";
        }
    }
    return 0;
}
