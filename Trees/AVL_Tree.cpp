#include <iostream>
using namespace std;

class Node {
    public:
        int info;
        Node* lc;
        Node* rc;
        int height;
        Node ( int i ) {
            info = i;
            lc = NULL;
            rc = NULL;
            height = 1;
        }
};

class AVL_Tree {
    public:
        Node* root;
        AVL_Tree();
        Node* insert(Node*,int);
        Node* remove(Node*,int);
        void traverse(Node*);
        void search(int);
        Node* rotate_left(Node*);
        Node* rotate_right(Node*);
        int get_height(Node*);
};

AVL_Tree :: AVL_Tree() {
    root = NULL;
}

int max ( int a, int b ) {
    return a > b ? a : b;
}

int AVL_Tree :: get_height ( Node* n ) {
    if ( n == NULL ) {
        return 0;
    }
    return n -> height;
}

Node* AVL_Tree :: rotate_left ( Node* n ) {
    Node* aux1 = n -> rc;   
    Node* aux2 = n -> rc -> lc;
    if ( n == root ) {
        root = aux1;
    }
    aux1 -> lc = n;
    n -> rc = aux2;
    n -> height = 1 + max(get_height(n->lc), get_height(n->rc));
    aux1 -> height = 1 + max(get_height(aux1->lc), get_height(aux1->rc));
    return aux1;   // returning the new root
}

Node* AVL_Tree :: rotate_right ( Node* n ) {
    Node* aux1 = n -> lc;
    Node* aux2 = n -> lc -> rc;
    if ( n == root ) {
        root = aux1;
    }
    aux1 -> rc = n;
    n -> lc = aux2;
    n -> height = 1 + max(get_height(n->lc), get_height(n->rc));
    aux1 -> height = 1 + max(get_height(aux1->lc), get_height(aux1->rc));
    cout<<aux1->info;
    return aux1;   // returning the new root
}

Node* AVL_Tree :: insert ( Node* curr_root, int info ) {
    if ( root == NULL ) {
        root = new Node(info);
        return root;
    }
    if ( curr_root == NULL ) {
        Node* n = new Node(info);
        return n;
    }
    if ( info < curr_root -> info ) {
        curr_root -> lc = insert (curr_root->lc, info);
    }
    else if ( info > curr_root -> info ) {
        curr_root -> rc = insert (curr_root->rc, info);
    }
    else {
        cout << "Two nodes cannot be similar in BST or AVL tree!" << endl;
        return curr_root;
    }
    curr_root -> height = 1 + max(get_height(curr_root->lc), get_height(curr_root->rc));
    int bf = get_height(curr_root->lc) - get_height(curr_root->rc);    // Balance Factor
    if ( bf == 0 || bf == 1 || bf == -1 ) {         // if the node if balanced then return it unchanged
        return curr_root;
    } 
    if ( bf > 1 ) {           // left heavy node initially
        if ( info < curr_root->lc->info ) {     // left left case, node was inserted in left subtree of left child
            return rotate_right(curr_root);   // rotate right once to restore balance
        }
        else if ( info > curr_root->lc->info) {    // left right case, node was inserted in right subtree of left child
            curr_root -> lc = rotate_left (curr_root->lc);  // rotate left about its left child once
            return rotate_right(curr_root);          // rotate right again to restore balance
        }
    }
    else if ( bf < -1 ) {     // right heavy node initially
        if ( info > curr_root->rc->info ) {    // right right case, node was inserted in right subtree of right child
            return rotate_left(curr_root);      // rotate left once to restore balance
        }
        else if (info < curr_root->rc->info ) {  // right left case, node was inserted in left subtree of right child
            curr_root -> rc = rotate_right (curr_root->rc);   // rotate right about its right child once
            return rotate_left(curr_root);
        }
    }
}

Node* AVL_Tree :: remove ( Node* curr_root, int info ) {
    if ( curr_root == NULL ) {
        cout << "Sorry! Element to be deleted not found in tree.\n";
        return curr_root;
    }
    if ( info < curr_root -> info ) {
        curr_root -> lc = remove (curr_root->lc, info);
    }
    else if ( info > curr_root -> info ) {
        curr_root -> rc = remove (curr_root->rc, info);
    }
    else {
        Node* extra = curr_root;
        if ( curr_root -> lc == NULL && curr_root -> rc == NULL ) {    // node to be deleted has no children
            if ( curr_root == root ) {
                root = NULL;
            }
            curr_root = NULL;
            delete extra;
        }
        else if ( curr_root -> lc != NULL && curr_root -> rc == NULL ) {     // node to be deleted has one child - left
            extra = curr_root -> lc;
            *curr_root = *extra;
            delete extra;
        }
        else if ( curr_root -> lc == NULL && curr_root -> rc != NULL ) {     // node to be deleted has one child - right
            extra = curr_root -> rc;
            *curr_root = *extra;
            delete extra;
        }
        else {                                                         // node to be deleted has two children
            Node* in_suc = curr_root -> rc;
            while ( in_suc -> lc != NULL ) {
                in_suc = in_suc -> lc;
            }
            curr_root -> info = in_suc -> info;
            in_suc -> info = info;
            curr_root -> rc = remove (curr_root -> rc, info);
        }
    }
    if ( curr_root == NULL ) {
        return curr_root;
    }
    curr_root -> height = 1 + max(get_height(curr_root->lc), get_height(curr_root->rc));
    int bf = get_height(curr_root->lc) - get_height(curr_root->rc);    // Balance Factor
    if ( bf == 0 || bf == 1 || bf == -1 ) {         // if the node is balanced then return it unchanged
        return curr_root;
    } 
    if ( bf > 1 ) {       
        int bfl = 0;
        if ( curr_root -> lc != NULL ) 
            bfl = get_height(curr_root->lc->lc) - get_height(curr_root->lc->rc);
        if ( bfl >= 0 ) {     // left left case
            return rotate_right(curr_root);   // rotate right once to restore balance
        }
        else {    // left right case
            curr_root -> lc = rotate_left (curr_root->lc);  // rotate left about its left child once
            return rotate_right(curr_root);          // rotate right again to restore balance
        }
    }
    else if ( bf < -1 ) {     // right heavy node initially
        int bfr = 0;
        if ( curr_root -> rc != NULL ) 
            bfr = get_height(curr_root->rc->lc) - get_height(curr_root->rc->rc);
        if ( bfr <= 0 ) {    // right right case, node was inserted in right subtree of right child
            return rotate_left(curr_root);      // rotate left once to restore balance
        }
        else {  // right left case, node was inserted in left subtree of right child
            curr_root -> rc = rotate_right (curr_root->rc);   // rotate right about its right child once
            return rotate_left(curr_root);
        }
    }
}

void AVL_Tree :: traverse ( Node* curr_root ) {      // inorder traversal
    if ( curr_root == NULL ) {
        return;
    }
    traverse ( curr_root -> lc );
    cout << curr_root -> info << " ";
    traverse ( curr_root -> rc );
}

int main() {    
    int ch;
    AVL_Tree avl;
    cout << "MENU :\n\t1. Traverse\n\t2. Insert\n\t3. Delete\n\t4. Exit\n";
    // Wohoo! You can now search in O(log(n)) time always ;)
    while ( true ) {
        cout << "Enter your choice : ";
        cin >> ch;
        int ele;
        switch(ch) {
            case 1:
                cout << "The traversal of the AVL tree is : ";
                avl.traverse(avl.root);
                cout << endl;
                break;
            case 2:
                cout << "Enter the element to be inserted : ";
                cin >> ele;
                avl.insert(avl.root, ele);
                break;
            case 3:
                cout << "Enter the element to be deleted : ";
                cin >> ele;
                avl.remove(avl.root, ele);
                break;
            case 4:
                cout << "Bye...";
                exit(0);
            default:
                cout << "Wrong choice entered!\n";
        }
    }
    return 0;
}
