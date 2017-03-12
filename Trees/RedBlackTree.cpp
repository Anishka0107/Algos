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
        void in_order_traversal();
        void rotate_left(Node*);
        void rotate_right(Node*);
        void fix_for_insert(Node*);
        void fix_for_remove(Node*);
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
    fix_for_insert (n);
}

void RedBlackTree :: remove (int ele) {
    Node* curr = root;
    while (curr != NULL) {
        if (curr -> info == ele) 
            break;
        if (curr -> info > ele) 
            curr = curr -> lc;
        else 
            curr = curr -> rc;
    }
    if (curr == NULL) {
        cout << "Element to be deleted not found!\n";
        return;
    }
    Node* temp;
    if (curr -> lc == NULL && curr -> rc == NULL) {
        if (curr == root) 
            root = NULL;
        else if (curr == curr -> parent -> lc)
            curr -> parent -> lc = NULL;
        else
            curr -> parent -> rc = NULL;
    }
    else if (curr -> lc != NULL && curr -> rc == NULL) {
        if (curr == root)
            root = curr -> lc;
        else if (curr == curr -> parent -> lc)
            curr -> parent -> lc = curr -> lc;
        else
            curr -> parent -> rc = curr -> lc;
        curr -> lc -> parent = curr -> parent;
        temp = curr -> lc;
    }
    else if (curr -> lc == NULL && curr -> rc != NULL) {
        if (curr == root)
            root = curr -> rc;
        else if (curr == curr -> parent -> lc)
            curr -> parent -> lc = curr -> rc;
        else
            curr -> parent -> rc = curr -> rc;
        curr -> rc -> parent = curr -> parent;
        temp = curr -> rc;
    }
    else {
        Node* ios = curr -> rc;
        while (ios -> lc != NULL) 
            ios = ios -> lc;
        curr -> info = ios -> info;
        if (ios -> rc != NULL) 
            ios -> rc -> parent = ios -> parent;
        if (ios == ios -> parent -> lc)
            ios -> parent -> lc = ios -> rc;
        else 
            ios -> parent -> rc = ios -> rc;
        temp = ios -> rc;
        curr = ios;
    }    
    colour col = curr -> c;
    delete curr;
    if (temp != NULL && col == BLACK)
        fix_for_remove (temp);
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
        cout << curr -> info << "[" << curr -> c << "]" << " ";
        q.pop();
        if (curr -> lc != NULL) 
            q.push (curr -> lc);
        if (curr -> rc != NULL) 
            q.push (curr -> rc);
    }
    cout << endl;
}

void RedBlackTree :: in_order_traversal() {
    if (root == NULL) {
        cout << "The tree is empty!\n";
        return;
    }
    stack<Node*> s;
    Node* curr = root;
    while (true) {
        while (curr != NULL) {
            s.push(curr);
            curr = curr -> lc;
        }
        if (!s.empty()) {
            cout << s.top() -> info << " ";
            curr = s.top() -> rc;
            s.pop();
        }
        else {
            cout << endl;
            return;
        }
    }    
}

void RedBlackTree :: rotate_left (Node* curr_root) {
    Node* aux = curr_root -> rc;
    curr_root -> rc = aux -> lc;
    if (aux -> lc != NULL)
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
    if (aux -> rc != NULL)
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

void RedBlackTree :: fix_for_insert (Node* n) {
    while ((n != root) && (n -> parent -> c == RED)) {
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
                n -> parent -> c = BLACK;
                n -> parent -> parent -> c = RED;
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
                n -> parent -> c = BLACK;
                n -> parent -> parent -> c = RED;
                rotate_left (n -> parent -> parent);
            }
        }
    }
    root -> c = BLACK;
}

void RedBlackTree :: fix_for_remove (Node *rep) {      // rep stands for the node which replaces the position of the deleted node
    Node* _sibling;
    while (rep != root && rep -> c == BLACK) {
        if (rep -> parent -> lc == rep) {
            _sibling = rep -> parent -> rc;
            if (_sibling -> c == RED) {
                _sibling -> c = BLACK;
                rep -> parent -> c = RED;
                rotate_left (rep -> parent);
                _sibling = rep -> parent -> rc;
            }
            if (_sibling -> rc -> c == BLACK && _sibling -> lc -> c == BLACK) {
                _sibling -> c = RED;
                rep = rep -> parent;
            }
            else {
                if (_sibling -> rc -> c == BLACK) {
                    _sibling -> lc -> c = BLACK;
                    _sibling -> c = RED;
                    rotate_right (_sibling);
                    _sibling = rep -> parent -> rc;
                }
                _sibling -> c = rep -> parent -> c;
                rep -> parent -> c = BLACK;
                _sibling -> rc -> c = BLACK;
                rotate_left (rep -> parent);
                rep = root;
            }
        }
        else {
            _sibling = rep -> parent -> lc;
            if (_sibling -> c == RED) {
                _sibling -> c = BLACK;
                rep -> parent -> c = RED;
                rotate_right (rep -> parent);
                _sibling = rep -> parent -> lc;
            }
            if (_sibling -> lc -> c == BLACK && _sibling -> rc -> c == BLACK) {
                _sibling -> c = RED;
                rep = rep -> parent;
            }
            else {
                if (_sibling -> lc -> c == BLACK) {
                    _sibling -> rc -> c = BLACK;
                    _sibling -> c = RED;
                    rotate_left (_sibling);
                    _sibling = rep -> parent -> lc;
                }
                _sibling -> c = rep -> parent -> c;
                rep -> parent -> c = BLACK;
                _sibling -> lc -> c = BLACK;
                rotate_right (rep -> parent);
                rep = root;
            }
        }
    }
    rep -> c = BLACK;
    root -> c = BLACK;
}

int main() {
    RedBlackTree rbt;
    cout << "MENU\n\t1. Insert\n\t2. Remove\n\t3. Traverse level order\n\t4. Traverse in order\n\t5. Exit\n";
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
                cout << "The level order traversal of the red black tree is : \n";
                rbt.level_order_traversal();
                break;
            case 4:
                cout << "The in order traversal of the red black tree is : \n";
                rbt.in_order_traversal();
                break;
            case 5:
                exit(1);
            default:
                cout << "Wrong choice entered!\n";
        }
    }
    return 0;
}
