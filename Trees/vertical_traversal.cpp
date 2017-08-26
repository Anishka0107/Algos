#include <bits/stdc++.h>
using namespace std;

class Node {
    public:
        int info;
        Node* lc;
        Node* rc;
        Node (int i) {
            info = i;
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
        void vertical_traverse();
};

void BT :: vertical_traverse() {
    map<int, vector<int>> hash;
    queue<pair<Node*, int>> q;
    q.push (make_pair (root, 0));
    while (!q.empty()) {
        pair<Node*, int> curr = q.front();
        q.pop();
        hash[curr.second].push_back (curr.first->info);
        if (curr.first->lc)
            q.push (make_pair (curr.first->lc, curr.second-1));
        if (curr.first->rc)
            q.push (make_pair (curr.first->rc, curr.second+1));
    }
    for (auto & node : hash) {
        for (int i=0; i<node.second.size(); i++)
            cout << node.second[i] << " ";
        cout << endl;
    }
}

int main() {
    BT bt;
    bt.root = new Node (1);
    bt.root->lc = new Node (2);
    bt.root->rc = new Node (3);
    bt.root->lc->lc = new Node (4);
    bt.root->lc->rc = new Node (5);
    bt.root->rc->lc = new Node (6);
    bt.root->rc->rc = new Node (7);
    bt.vertical_traverse();
    return 0;
}
