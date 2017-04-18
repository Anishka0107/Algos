#include <iostream>
#define SIZE 26    // size of the alphabet set
using namespace std;

class Node {
    public:
        Node* children[SIZE];
        bool is_leaf;
        Node() {
            for (int i = 0; i < SIZE; i++)
                children[i] = NULL;
            is_leaf = false;
        }
};

class Trie {
    public:
        Node* root;
        Trie() {
            root = new Node();
        }
        void insert (string);
        bool remove (string, Node*, int);
        bool search (string);
};

void Trie :: insert (string s) {
    Node* curr = root;
    for (int i = 0; i < s.length(); i++) {
        int idx = (int)s[i] - (int)'a';
        if (curr -> children[idx] == NULL) 
            curr -> children[idx] = new Node();
        curr = curr -> children[idx];
    }
    curr -> is_leaf = true;      // the last letter of the string is the leaf node
}

bool Trie :: remove (string s, Node* curr, int curr_depth) {
    if (curr != NULL) {
        if (curr_depth == s.length()) {
            if (curr -> is_leaf) {
                curr -> is_leaf = false;
                for (int i = 0; i < SIZE; i++) {
                    if (curr -> children[i] != NULL) {
                        curr = NULL;
                        return true;
                    }
                    return false;
                }        
            }
        }
        else {
            int idx = (int)s[curr_depth] - (int)'a';
            if (remove(s, curr -> children[idx], curr_depth + 1)) {
                curr -> children[idx] = NULL;
                delete curr -> children[idx];
                bool no_children = true;
                for (int i = 0; i < SIZE; i++) {
                    if (curr -> children[i] != NULL) {
                        no_children = false;
                        break;
                    }
                }
                return (!curr -> is_leaf && no_children);
            }
        }
    }
    return false;
}

bool Trie :: search (string s) {
    Node* curr = root;
    for (int i = 0; i < s.length(); i++) {
        int idx = (int)s[i] - (int)'a';
        if (curr -> children[idx] == NULL)
            return false;
        curr = curr -> children[idx];
    }
    return curr -> is_leaf;      // we return true only if it a leaf node, else we return false as it is just a prefix
}

int main() {
    Trie t;
    cout << "MENU:\n\t1. Insert\n\t2. Delete\n\t3. Search\n\t4. Exit\n";
    while (true) {
        int ch;
        cout << "Enter your choice : ";
        cin >> ch;
        string s, text;
        if (ch == 1 || ch == 2 || ch == 3) {
            cout << "Enter the string on which you wish to perform this operation : ";
            cin >> s;
        }
        switch (ch) {
            case 1:
                t.insert (s);
                break;
            case 2:
                t.remove (s, t.root, 0);
                break;
            case 3:
                text = t.search (s) ? "String exists!\n" : "Sorry! The string does NOT exist!\n";
                cout << text;
                break;
            case 4:
                return 0;
            default:
                cout << "Wrong choice entered!";
        }
    }
    return 0;
}
