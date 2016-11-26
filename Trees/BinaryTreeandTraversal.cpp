#include <bits/stdc++.h>

class Node {
    public:
    int info;    
    Node *lc;   // left child
    Node *rc;   // right child
    Node() {
        lc = NULL;
        rc = NULL;
    }
    Node(int ele) {
        info = ele;
        lc = NULL;
        rc = NULL;
    }
};

class BinaryTree {
    public:
    Node *root;
    BinaryTree() {
        root = NULL;
    }
    void level_order_traversal();    // basically BFS
    void inorder_traversal();        // basically DFS
    void preorder_traversal();       // basically DFS
    void postorder_traversal();      // basically DFS
};

void BinaryTree :: level_order_traversal() {
    
}

void BinaryTree :: inorder_traversal() {
    
}

void BinaryTree :: preorder_traversal() {
    
}

void BinaryTree :: postorder_traversal() {
    
}

int main () {
    BinaryTree bt;
    // Creating a custom tree
    bt.root = new Node(2);
    
    return 0;
}