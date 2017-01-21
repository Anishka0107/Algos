#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Node {
    public :
        int info;
        Node *lc;
        Node *rc;
        Node (int ele) {
            lc = NULL;
            rc = NULL;
            info = ele;
        }
};

vector<int> v;

void inorder (Node *curr_root) {
    if (curr_root == NULL) {
        return;
    }
    inorder (curr_root -> lc);
    v.push_back (curr_root -> info);
    inorder (curr_root -> rc);
}

bool check_if_BST (Node* root) {
    inorder(root);
    bool result;
    result = is_sorted (v.begin(), v.end());
    if (result == false) {
        return false;
    }
    result = unique (v.begin(), v.end()) == v.end();
    return result;
}

int main () {
    Node *root1 = new Node(40);
    root1 -> lc = new Node(30);
    root1 -> lc -> lc = new Node(20);
    root1 -> rc = new Node(50);
    root1 -> rc -> lc = new Node(45);
    root1 -> rc -> rc = new Node(60);
    root1 -> rc -> rc -> lc = new Node(55);
    root1 -> rc -> rc -> rc = new Node(80);
    root1 -> rc -> rc -> rc -> lc = new Node(70);
    bool final_result = check_if_BST(root1);   // true ---> BST ;  false ---> not a BST
    return 0;
}
