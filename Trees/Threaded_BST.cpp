#include <iostream>
using namespace std;

class Node {
    public :
        int info;
        Node* lc;      // left child
        Node* rc;      // right child
        bool lt;       // true if thread, false if link
        bool rt;
        Node (int info) {
            this -> info = info;
            lc = NULL;
            rc = NULL;
            lt = false;
            rt = false;
        }
        Node() {   // empty constructor
            lc = NULL;
            rc = NULL;
            lt = false;
            rt = false;
        }
};

class TBST {
    public :
        Node* head;
        TBST() {
            head = new Node();
            head -> lc = head;      
            head -> rc = head;
        }
        void inorder_traversal();    // implementing inorder traversal beacuse threaded bst is implemented as an inorder compliant
        void insert ( int ele );
        void remove ( int ele );
        void search ( int ele );
};

void TBST :: inorder_traversal() {
    if ( head -> lc == head ) {
        cout << "The tree is empty!\n";
        return;
    }
    Node* curr = head -> lc;    // pointing to the root of TBST
    while ( curr -> lt != true ) {
        curr = curr -> lc;
    }                           // now it is pointing to the leftmost node in the tree
    cout << curr -> info << " ";
    while ( curr -> rc != head ) {
        if ( curr -> rt == true ) {
            curr = curr -> rc;
            cout << curr -> info << " ";
            continue;
        }
        else {
            curr = curr -> rc;
            while ( curr -> lt != true ) {
                curr = curr -> lc;
            } 
            cout << curr -> info << " ";
        }
    }
    cout << endl;
}

void TBST :: insert ( int ele ) {
    Node* n = new Node (ele);
    if ( head -> lc == head ) {              // the tree is empty
        head -> lc = n;
        n -> lc = head;
        n -> rc = head;
        n -> lt = true;
        n -> rt = true;
        return;
    }
    Node* parent = head;
    Node* curr = head -> lc;
    while ( curr != NULL ) {
        parent = curr;
        if ( ele < curr -> info ) {
            if ( curr -> lt == true ) {
                curr = NULL;
                break;
            } 
            curr = curr -> lc;
        }
        else {
            if ( curr -> rt == true ) {
                curr = NULL;
                break;
            }
            curr = curr -> rc;
        }
    }
    if ( ele < parent -> info ) {
        n -> lc = parent -> lc;
        n -> lt = parent -> lt;
        n -> rc = parent;
        n -> rt = true;
        parent -> lc = n;
        parent -> lt = false;
    }
    else {
        n -> rc = parent -> rc;
        n -> rt = parent -> rt;
        n -> lc = parent;
        n -> lt = true;
        parent -> rc = n;
        parent -> rt = false;
    }
}

void TBST :: remove ( int ele ) {
    if ( head -> lc == head ) {
        cout << "The tree is empty!!\n";
        return;
    }
    Node* parent = head;
    Node* curr = parent -> lc;
    while ( curr != NULL && curr -> info != ele ) {
        parent = curr;
        if ( curr -> info > ele ) {
            if ( curr -> lt == false ) {
                curr = curr -> lc;
            }
            else {
                curr = NULL;
            }
        }
        else {
            if ( curr -> rt == false ) {
                curr = curr -> rc;
            }
            else {
                curr = NULL;
            }
        }
    }
    if ( curr == NULL ) {
        cout << "Sorry! Node to be deleted not found!!\n";
        return;
    }
    if ( curr -> lt == true && curr -> rt == true ) {       // the node to be deleted is a leaf node    
        if ( curr == head -> lc ) {     // node to be deleted is root node
            head -> lc = head;
            delete curr;
            return;
        }
        if ( curr == parent -> lc ) {
            parent -> lc = curr -> lc;
            parent -> lt = true;
        }
        else if ( curr == parent -> rc ) {
            parent -> rc = curr -> rc;
            parent -> rt = true;
        }
        delete curr;
    }
    else if ( curr -> lt == true || curr -> rt == true ) {     // the node to be deleted has 1 child
        Node *subtree;
        if ( curr -> lt == false ) {      // curr has a left child / subtree
            subtree = curr -> lc;
        }
        else {                            // curr has a right child / subtree
            subtree = curr -> rc;
        }
        if ( curr == parent -> lc ) {     // curr is the left child of the parent
            parent -> lc = subtree;
        }
        else {
            parent -> rc = subtree;       // curr is the right child of the parent
        }
        Node *insuc = curr -> rc, *inpred = curr -> lc;
        if ( subtree == curr -> rc ) {
            while ( insuc -> lt == false ) {
                insuc = insuc -> lc;
            }
        }
        if ( subtree == curr -> lc ) {
            while ( inpred -> rt == false ) {
                inpred = inpred -> rc;
            }
        }
        if ( subtree == curr -> lc ) {
            inpred -> rc = insuc;   
            inpred -> rt = true;
        }
        else {
            insuc -> lc = inpred;
            insuc -> lt = true;
        }
        delete curr;
    }
    else {
        Node* in_suc = curr -> rc;
        Node* in_suc_par = curr;                
        while ( in_suc -> lt == false ) {             // inorder successor of the node to be deleted
            in_suc_par = in_suc;
            in_suc = in_suc -> lc;
        }
        int infos = in_suc -> info;
        remove (infos);
        curr -> info = infos;
    }
}

void TBST :: search ( int ele ) {
    if ( head -> lc == head ) {
        cout << "The tree is empty!!\n";
        return;
    }
    Node* curr = head -> lc;
    while ( curr != NULL && curr -> info != ele ) {
        if ( curr -> info > ele ) {
            if ( curr -> lt == false ) {
                curr = curr -> lc;
            }
            else {
                curr = NULL;
            }
        }
        else {
            if ( curr -> rt == false ) {
                curr = curr -> rc;
            }
            else {
                curr = NULL;
            }
        }
    }
    if ( curr == NULL ) {
        cout << "Sorry! Element not found!" << endl;
    }
    else {
        cout << "Wohoo! Element found." << endl;
    }
}

int main() {
    TBST tree;
    int ch;
    char c;
    cout << "MENU\n\t1. Traverse\n\t2. Insert\n\t3. Delete\n\t4. Search\n"; 
    do {
        cout << "Enter your choice : ";
        cin >> ch;
        int ele;
        switch (ch) {
            case 1 :
                cout << "The inorder traversal of the tree is : ";
                tree.inorder_traversal();
                break;
            case 2 :
                cout << "Enter the element to be inserted : ";
                cin >> ele;
                tree.insert (ele);
                break;
            case 3 :
                cout << "Enter the element to be deleted : ";
                cin >> ele;
                tree.remove (ele);
                break;
            case 4 :
                cout << "Enter the element to be searched for : ";
                cin >> ele;
                tree.search (ele);
                break;
            default : 
                cout << "Wrong choice entered!!\n";
        }
        cout << "Do you wish to continue? ";
        cin >> c;
    }
    while ( c == 'Y' || c == 'y' );
    return 0;
}

