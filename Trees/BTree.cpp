#include <bits/stdc++.h>
using namespace std;

class Node {
    public:
        int n;        // the number of keys, though its unecessary (as a vector is being used), I am keeping it here to not lose the essence of a b-tree node
        vector<int> info;
        vector<Node*> children;
        bool is_leaf;
        Node (bool _leaf) {
            n = 0;
            is_leaf = _leaf;
        }
};

class BTree {
    public:
        Node* root;
        int b;
        BTree (int b) {
            this->b = b;
            root = NULL;
        }
        void traverse (Node*);     // inorder traversal
        void insert (int);
        void remove (int);
        int search (Node*, int);
        // helper methods
        void insert_into_node (int, Node*);                 // this method is called when a node has space for insertion of an element
        void split_child (int, Node*, Node*);               // this method is called only when the node is full (i.e., it has 2*b-1 keys)
        void remove_from_node (int, Node*);
        void merge (int, Node*);
        void elongate_node (int, Node*);
};

void BTree :: traverse (Node* curr_root) {
    if (curr_root != NULL) {
        int i;
        for (i = 0; i < curr_root->n; i++) {
            if (!curr_root->is_leaf)
                traverse (curr_root->children[i]);
            cout << curr_root->info[i] << " ";
        }
        if (!curr_root->is_leaf)
            traverse (curr_root->children[i]);
    }
}

void BTree :: insert (int ele) {
    if (root == NULL) {        // tree is empty
        root = new Node (true);
        root->info.push_back (ele);   // inserted at 0th position
        root->n++;
    }
    else {
        if (root->n == 2*b-1) {     // the tree is full
            Node* new_root = new Node (false);
            new_root->children.push_back (root);        // old root inserted as 0th position child of new root
            split_child (0, root, new_root);
            int pos = new_root->info[0] > ele ? 0 : 1;   // we are choosing the child of the new root into which the new element would be inserted
            insert_into_node (ele, new_root->children[pos]);
            root = new_root;
        }
        else
            insert_into_node (ele, root);       // the root is not full, so we may insert directly
    }
}

void BTree :: insert_into_node (int ele, Node* node) {
    if (node->is_leaf == true) {
        int pos;
        for (pos = 0; pos < node->n && ele > node->info[pos]; pos++);
        node->info.insert (node->info.begin() + pos, ele);
        node->n++;
    }
    else {
        int idx;
        for (idx = 0; idx < node->n && ele > node->info[idx]; idx++);     // find the child into which the new element is to be inserted
        if (node->children[idx]->n == 2*b-1) {           // the child into which we have to insert is full
            split_child(idx, node->children[idx], node);
            idx = (node->info[idx] > ele) ? idx : (idx+1);
        }
        insert_into_node (ele, node->children[idx]);
    }
}

void BTree :: split_child (int i, Node* child, Node* parent) {
    Node* new_child = new Node (child->is_leaf);
    new_child->n = b - 1;
    child->n = b - 1;
    for(int i = 0; i < b-1; i++) {
        new_child->info.insert (new_child->info.begin(), child->info.back());
        child->info.pop_back();
    }
    if (child->is_leaf == false) {
        for (int i = 0; i < b; i++) {
            new_child->children.insert (new_child->children.begin(), child->children.back());
            child->children.pop_back();
        }
    }
    parent->children.insert (parent->children.begin() + i+1, new_child);
    parent->info.insert (parent->info.begin() + i, child->info[b-1]);
    child->info.pop_back();
    parent->n++;
}

void BTree :: remove (int ele) {
    if (root == NULL) {
        cout << "Sorry! The tree is empty.\n";
        return;
    }
    remove_from_node (ele, root);
    if (root->n == 0) {
        Node* temp = root;
        if (root->is_leaf == true)
            root = NULL;
        else
            root = root->children[0];
        delete temp;
    }
}

void BTree :: remove_from_node (int ele, Node* curr_root) {
    int pos;
    for (pos = 0; pos < curr_root->n && ele > curr_root->info[pos]; pos++);
    if (pos < curr_root->n && curr_root->info[pos] == ele) {        //element found in current node
        if (curr_root->is_leaf) {
            curr_root->info.erase (curr_root->info.begin() + pos);
            curr_root->n--;
        }
        else {
            int temp = curr_root->info[pos];
            if (curr_root->children[pos]->n >= b) {
                Node* pred = curr_root->children[pos];
                while (!pred->is_leaf)
                    pred = pred->children[pred->n];
                curr_root->info[pos] = pred->info[pred->n - 1];
                remove_from_node (pred->info[pred->n - 1], curr_root->children[pos]);
            }
            else if (curr_root->children[pos+1]->n >= b) {
                Node* succ = curr_root->children[pos+1];
                while (!succ->is_leaf)
                    succ = succ->children[0];
                curr_root->info[pos] = succ->info[0];
                remove_from_node (succ->info[0], curr_root->children[pos+1]);
            }
            else {
                merge (pos, curr_root);
                remove_from_node (temp, curr_root->children[pos]);
            }
        }
    }
    else {              // element not found in current node, so checking if it is present in child nodes
        if (curr_root->is_leaf) {
            cout << "Sorry! Key not found!\n";
            return;
        }
        int orig_len = curr_root->n;
        if (curr_root->children[pos]->n < b)
            elongate_node (pos, curr_root);
        if (orig_len == pos && orig_len > curr_root->n)    // this is true if the last two child nodes of curr_root got merged
            remove_from_node (ele, curr_root->children[pos-1]);
        else
            remove_from_node (ele, curr_root->children[pos]);
    }
}

void BTree :: merge (int idx, Node* curr_root) {
    Node* child_left = curr_root->children[idx];
    Node* child_right = curr_root->children[idx+1];
    child_left->info.push_back (curr_root->info[idx]);        // inserted always at the (b-1)th position
    for (int i = 0; i < child_right->n; i++)
        child_left->info.push_back (child_right->info[i]);
    if (!child_left->is_leaf) {
        for (int i = 0; i <= child_right->n; i++)
            child_left->children.insert (child_left->children.begin() + i+b, child_right->children[i]);
    }
    curr_root->info.erase (curr_root->info.begin() + idx);
    curr_root->children.erase (curr_root->children.begin() + idx+1);
    child_left->n += child_right->n + 1;
    curr_root->n--;
    delete child_right;
}

void BTree :: elongate_node (int idx, Node* curr_root) {
    if (idx != 0 && curr_root->children[idx-1]->n >= b) {     // if the previous child has more than b-1 elements, we extract an element from it
        Node* child = curr_root->children[idx];
        Node* sibling = curr_root->children[idx-1];
        child->info.insert (child->info.begin(), curr_root->info[idx-1]);
        if (!child->is_leaf)
            child->children.insert (child->children.begin(), sibling->children[sibling->n]);
        sibling->children.pop_back();
        curr_root->info[idx-1] = sibling->info[sibling->n - 1];
        sibling->info.pop_back();        // or, equivalently, sibling->info.erase (sibling->info.end()-1)
        child->n++;
        sibling->n--;
    }
    else if (idx != curr_root->n && curr_root->children[idx+1]->n >= b) {  // if the next child has more than b-1 elements, extract from it
        Node* child = curr_root->children[idx];
        Node* sibling = curr_root->children[idx+1];
        child->info.insert (child->info.end(), curr_root->info[idx]);
        if (!child->is_leaf)
            child->children.insert (child->children.end(), sibling->children[0]);
        curr_root->info[idx] = sibling->info[0];
        sibling->info.erase (sibling->info.begin());
        if (!sibling->is_leaf)
            sibling->children.erase (sibling->children.begin());
        child->n++;
        sibling->n--;
    }
    else {           // merging curr_root->children[idx] with its left or right sibling
        if (idx == curr_root->n)
            merge (idx-1, curr_root);     // merging with left sibling, as it is the last child
        else
            merge (idx, curr_root);       // merging with right sibling
    }
}

int BTree :: search (Node* curr_root, int ele) {
    if (curr_root == NULL)
        return 0;
    int i;
    for (i = 0; i < curr_root->n && curr_root->info[i] < ele; i++);
    if (curr_root->info[i] == ele)            // we have found the node
        return 1;
    if (curr_root->is_leaf == true)           // we cannot find this node anymore as it has no children
        return 0;
    return search (curr_root->children[i], ele);
}

int main() {
    int b;
    cout << "Enter the value of the factor b : ";
    cin >> b;
    BTree bt (b);
    cout << "MENU\n\t1. Traverse\n\t2. Insert\n\t3. Delete\n\t4. Search\n\t5. Exit\n";
    while (true) {
        int ch, ele;
        string res;
        cout << "Enter your choice : ";
        cin >> ch;
        switch (ch) {
            case 1:
                cout << "The inorder traversal of the tree is : ";
                bt.traverse (bt.root);
                cout << endl;
                break;
            case 2:
                cout << "Enter the element to be inserted : ";
                cin >> ele;
                bt.insert (ele);
                break;
            case 3:
                cout << "Enter the element to be deleted : ";
                cin >> ele;
                bt.remove (ele);
                break;
            case 4:
                cout << "Enter the element to be searched for : ";
                cin >> ele;
                res = bt.search (bt.root, ele) == 1 ? "Element found!" : "Element NOT found!";
                cout << res << endl;
                break;
            case 5:
                exit(1);
                break;
            default:
                cout << "Wrong choice entered!\n";
        }
    }
    return 0;
}
