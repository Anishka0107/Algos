#include <iostream>
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

// lowest common ancestor in binary tree; for bst, can be done more easily

Node* lca (Node* curr, Node* x, Node* y) {
    if (curr == NULL || curr == x || curr == y)
        return curr;
    Node* par1 = lca (curr->lc, x, y);
    Node* par2 = lca (curr->rc, x, y);
    if (par1 == NULL && par2 == NULL)
        return NULL;
    if (par1 == par2)
        return par1;
    if (par1 != NULL && par2 != NULL)
        return curr;
    if(par1 != NULL)
        return par1;
    if(par2 != NULL)
        return par2;
}

int main() {
    Node* root = new Node(1);
    root->lc = new Node(2);
    root->rc = new Node(3);
    root->lc->lc = new Node(4);
    root->lc->rc = new Node(5);
    root->rc->lc = new Node(6);
    root->rc->rc = new Node(7);
    root->rc->lc->rc = new Node(8);
    cout << lca (root, root->rc->rc, root->rc->lc->rc) -> info;
    return 0;
}
