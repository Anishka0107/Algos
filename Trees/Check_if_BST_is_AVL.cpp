#include <iostream>
using namespace std;

class Node {
    public:
        int info;
        Node* lc;
        Node* rc;
        Node (int info) {
            this -> info = info;
            lc = NULL;
            rc = NULL;
        }
};

class Tree {
    public:
        Node* root;
        Tree() {
            root = NULL;
        }
        void inorder_traversal (Node*);
};

void Tree :: inorder_traversal (Node* root) {                // without using stack and recursion
    if (root == NULL) {
        cout << "The tree is empty!\n";
        return;
    }
    Node* curr = root;
    while (curr != NULL) {
        if (curr -> lc == NULL) {
            cout << curr -> info << " ";
            curr = curr -> rc;
        }
        else {
            Node* pred = curr -> lc;              // inorder predecessor of the current node
            while (pred -> rc != NULL && pred -> rc != curr) {
                pred = pred -> rc;
            }
            if (pred -> rc == NULL) {              // the thread has not been not created yet, so creating it here
                pred -> rc = curr;
                curr = curr -> lc;
            }
            else {                  // the thread is present, so removing it, printing current node's info and pointing curr to it's right child
                cout << curr -> info << " ";
                pred -> rc = NULL;
                curr = curr -> rc;
            }
        }
    }
    cout << endl;
}

int max (int a, int b) {
    return a > b ? a : b;
}

int height (Node* root) {
    if (root == NULL) 
        return 0;
    return 1 + max (height (root -> lc), height (root -> rc));
}

bool isAVL (Node* root) {
    if (root == NULL)
        return true;
    int bal = height (root -> lc) - height (root -> rc);
    if (bal <= 1 && bal >= -1) {
        if (isAVL (root -> lc) && isAVL (root -> rc)) {
            return true;
        }
    }
    return false;
}

int main() {
    Tree t;
    t.root = new Node(10);
    t.root -> lc = new Node(5);
    t.root -> rc = new Node(15);
    t.root -> lc -> lc = new Node(2);
    cout << "This tree is (inorder) : ";
    t.inorder_traversal (t.root);
    if (isAVL (t.root))                // gives no understanding to user, but the programmer knows why the tree is AVL or not
        cout << "This BST is an AVL tree!\n";
    else
        cout << "This BST is NOT an AVL tree!\n";
    t.root -> rc -> lc = new Node(12);
    t.root -> rc -> lc -> rc = new Node(14);
    cout << "Now, the tree is (inorder) : ";
    t.inorder_traversal (t.root);
    if (isAVL (t.root))                // gives no understanding to user, but the programmer knows why the tree is AVL or not
        cout << "This BST is an AVL tree!\n";
    else
        cout << "This BST is NOT an AVL tree!\n";
   
    return 0;
}
