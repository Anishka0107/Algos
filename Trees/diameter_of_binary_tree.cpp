#include <bits/stdc++.h>
using namespace std;

class Node {
    public:
        int info;
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
        int diameter (Node*, int &);
};

int BT :: diameter (Node* curr, int & height) {
    if (curr == NULL) {
        height = 0;
        return 0;
    }
    int lh, rh;
    int diaml = diameter (curr->lc, lh);
    int diamr = diameter (curr->rc, rh);
    height = 1 + max (lh, rh);
    int maxim = max (max (diaml, diamr), 1 + lh + rh);
    return maxim;
}

int main() {
    BT bt;
    bt.root = new Node (1);
    bt.root->lc = new Node (2);
    bt.root->rc = new Node (3);
    bt.root->lc->lc = new Node (4);
    bt.root->lc->rc = new Node (5);
    bt.root->rc->rc = new Node (6);
    bt.root->lc->rc->lc = new Node (7);
    bt.root->lc->rc->rc = new Node (8);
    bt.root->rc->rc->rc = new Node (9);
    bt.root->rc->rc->rc->lc = new Node (10); 
    bt.root->rc->rc->rc->rc = new Node (11); 
    bt.root->rc->rc->rc->lc->lc = new Node (12);
    bt.root->rc->rc->rc->lc->rc = new Node(13);
    int temp;
    cout << bt.diameter (bt.root, temp);
    return 0;
}
