#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

class Node {
    public :
        int info;
        Node* lc;
        Node* rc;
        Node (int ele) {
            info = ele;
            lc = NULL;
            rc = NULL;
        }
};

vector<int> v;

void inorder_generate (Node* curr_root) {
    if (curr_root == NULL) {
        return;
    }
    inorder_generate (curr_root -> lc);
    v.push_back (curr_root -> info);
    inorder_generate (curr_root -> rc);
}

int count = 0;

void inorder_publish (Node *curr_root) {
    if (curr_root == NULL) {
        return;
    }
    inorder_publish (curr_root -> lc);
    curr_root -> info = v[::count];
    ::count++;
    inorder_publish (curr_root -> rc);
}

void inorder_traverse (Node *curr_root) {
    if (curr_root == NULL) {
        return;
    }
    inorder_traverse (curr_root -> lc);
    cout << curr_root -> info << " ";
    inorder_traverse (curr_root -> rc);
}

void convert_BT_to_BST (Node* root) {
    inorder_generate (root);
    sort (v.begin(), v.end());
    inorder_publish (root);
}

int main() {
    Node *root = new Node(10);
    root -> lc = new Node(6);
    root -> rc = new Node(8);
    root -> lc -> lc = new Node(9);
    root -> lc -> rc = new Node(7);
    cout << "The inorder traversal of the binary tree is : ";
    inorder_traverse (root);
    convert_BT_to_BST (root);
    cout << "\nThe inorder traversal of the equivalent binary search tree is : ";
    inorder_traverse (root);
    return 0;
}
