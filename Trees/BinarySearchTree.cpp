#include <iostream>
using namespace std;

class Node {
    public:
	int info;
	Node* lc;
	Node* rc;
        Node(int ele) {
	    lc = NULL;
	    rc = NULL;
	    info = ele;
	}
};

class BinarySearchTree {
    public:
	Node* root;
	BinarySearchTree() {
	    root = NULL;	
	}
    int search(int);
	void insert(int);
	int remove(int);
	void traverse(Node*);
};

int BinarySearchTree :: search (int ele) {
	Node* curr = root;
	while (true) {
		if (curr == NULL) {
			cout << "Element not found!\n";
            return -1;
		}
		else if (curr -> info == ele) {
            cout << "Element found!\n";			
            return 1;
		}
		else if (curr -> info > ele) {
            curr = curr -> lc;
		}
		else {
			curr = curr -> rc;
		}
	}
}

void BinarySearchTree :: insert (int ele) {
	Node* ins = new Node(ele);
	Node *curr = root;
	Node *parent = NULL;
	if (curr == NULL) {
		root = ins;
		return;
	}
	while (curr != NULL) {
		if (curr->info > ele) {
			parent = curr;
			curr = curr->lc;
		} 
		else if (curr->info < ele) {
			parent = curr;
			curr = curr->rc;
		}
	}
	if (parent->info > ele) {
		parent -> lc = ins;
	}
	else {
		parent -> rc = ins;
	}
}

int BinarySearchTree :: remove (int ele) {
	Node *curr = root;
	Node *parent = root;
	while (curr != NULL) {            // locate the node to be deleted and its parent
		if (curr -> info == ele) {
			break;
		}
		parent = curr;
		if (curr -> info > ele) {
			curr = curr -> lc;
		}
		else {
			curr = curr -> rc;
		}
	}   
	if (curr == NULL) {
		cout << "Element to be deleted not found!!\n";
		return -1;
	}
	if (curr -> lc == NULL && curr -> rc == NULL) {     // the node to be deleted is a leaf node
        if (curr == root) {
			root = NULL;
		}
		else if (curr == parent -> lc) {
			parent -> lc = NULL;
		}
		else {
			parent -> rc = NULL;
		}
		delete curr;
	}
	else if ((curr -> lc == NULL && curr -> rc != NULL) || (curr -> lc != NULL && curr -> rc == NULL)) {   // the node to be deleted has 1 child
		Node *child;
		if (curr -> lc != NULL) {
			child = curr -> lc;
		}
		else {
			child = curr -> rc;
		}
		if (curr == root) {
			root = child;
		}
		else if (curr == parent -> lc) {
			parent -> lc = child;
		}
		else {
			parent -> rc = child;
		}
		delete curr;
	}
    else {     // the node to be deleted has 2 children
		Node *ios = curr -> rc;    // will store inorder successor of the node to be deleted
		while (ios -> lc != NULL) {
			ios = ios -> lc;
		}
		int infos = ios -> info;
        remove (infos);
        curr -> info = infos;
    }
}

void BinarySearchTree :: traverse (Node* curr_root) {
    if (curr_root == NULL) {
        return;
    }
    traverse (curr_root -> lc);
    cout << curr_root -> info << " ";
    traverse (curr_root -> rc);
}

int main() {
    char ch;
    int c;
    BinarySearchTree bst;
    cout << "MENU :\n1. Insert\n2. Delete\n3. Search\n4. Traverse\n";
    do {
        cout << "Enter the operation which you wish to perform : ";
		cin >> c;
		int ele;
		switch (c) {
	    	case 1: 
	        	cout << "Enter the element to be inserted : ";
        		cin >> ele;
				bst.insert(ele);
				break;
	    	case 2:
				cout << "Enter the element to be deleted : ";
				cin >> ele;
				bst.remove(ele);
				break;
	    	case 3:
				cout << "Enter the element to be searched for : ";
				cin >> ele;
				bst.search(ele);
				break;
			case 4:
				cout << "The inorder traversal of the binary tree is : ";
				bst.traverse(bst.root);
                cout << endl;                
                break;    	
			default:
				cout << "Wrong choice entered!!\n";
		}	
		cout << "Do you wish to continue : ";
		cin >> ch;
    } while (ch == 'Y' || ch == 'y');
    return 0;
}
