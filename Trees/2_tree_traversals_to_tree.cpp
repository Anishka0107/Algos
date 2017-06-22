#include <bits/stdc++.h>
using namespace std;

// We can uniquely identify our binary tree if 2 traversals (preorder and inorder or postorder and inorder or levelorder and inorder) are provided

class Node {
    public:
        char info;
        Node* lc;
        Node* rc;
        Node (int info) {
            this->info = info;
            lc = NULL;
            rc = NULL;
        }
};

class BT {
    public:
        Node* root;
        BT() {
            root = NULL;
        }
        void verify_by_inorder (Node*);
        void verify_by_postorder (Node*);
};

void BT :: verify_by_inorder (Node* curr_root) {
    if (curr_root == NULL)
        return;
    verify_by_inorder (curr_root->lc);
    cout << curr_root->info << " ";
    verify_by_inorder (curr_root->rc);
}

void BT :: verify_by_postorder (Node* curr_root) {
    if (curr_root == NULL)
        return;
    verify_by_postorder (curr_root->lc);
    verify_by_postorder (curr_root->rc);
    cout << curr_root->info << " ";
}

int search (const string & s, char c, int start, int end) {
    for (int i=start; i<=end; i++) {
        if (s[i] == c) {
            return i;
        }
    }
    return -1;
}

Node* construct_bt (const string & pre, const string & in, int & pre_idx, int in_st, int in_end) {
    if (in_st > in_end)
        return NULL;
    Node* n = new Node (pre[pre_idx]);
    int in_idx = search (in, pre[pre_idx], in_st, in_end);
    if (in_idx == -1) {
        cout << "Some error in traversal sequences!!";
        exit(1);
    }
    pre_idx++;
    n->lc = construct_bt (pre, in, pre_idx, in_st, in_idx-1);
    n->rc = construct_bt (pre, in, pre_idx, in_idx+1, in_end);
    return n;
}

int main() {
    string pre, in;
    cin >> pre;          // preorder traversal
    cin >> in;           // inorder traversal
    BT bt;
    int t;
    bt.root = construct_bt (pre, in, t, 0, in.length()-1);
    bt.verify_by_inorder (bt.root);
    cout << endl;
    bt.verify_by_postorder (bt.root);
    return 0;
}
