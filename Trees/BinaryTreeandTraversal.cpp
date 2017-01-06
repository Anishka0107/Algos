#include <iostream>
using namespace std;

class Node {
    public:
	int info;
	Node *lc;
	Node *rc;
	Node(int ele) {
	    info = ele;
	    lc = NULL;
	    rc = NULL;
	}
};

class BinaryTree {
    public:
	Node *root;
    	BinaryTree() {
	    root = NULL;
	}
	void level_order_traversal();
	void pre_order_traversal();
	void in_order_traversal();
	void post_order_traversal();
};

class Extra {
    public:
        Node *x;
        Extra *next;
	Extra() {
	    x = NULL;
	    next = NULL;
	}
};
Extra *front = NULL;
Extra *back = NULL;

void insert (Extra *ele) {
    back -> next = ele;
    back = back -> next;
}

void remove() {
    Extra *temp = front;
    front = front -> next;
    delete temp;
}

void BinaryTree :: level_order_traversal() {
    Extra *ex = new Extra;
    ex -> x = root;
    front = ex;
    back = ex;
    while (front != NULL) {
        cout << front -> x -> info << " ";
	if (front -> x -> lc != NULL){
	    ex = new Extra;
	    ex -> x = front -> x -> lc;
	    insert(ex);
	}
	if (front -> x -> rc != NULL){
            ex = new Extra;
	    ex -> x= front -> x -> rc;
	    insert(ex);
	}
	remove();
    }
}

void BinaryTree :: pre_order_traversal() {

}

void BinaryTree :: in_order_traversal() {

}

void BinaryTree :: post_order_traversal(){

}

int main() {
    BinaryTree bt;
    // Creating a custom binary tree
    bt.root = new Node(1);
    bt.root -> lc = new Node(2);
    bt.root -> rc = new Node(3);
    bt.root -> lc -> lc = new Node(4);
    bt.root -> lc -> rc = new Node(5);
    bt.root -> rc -> lc = new Node(6);
    bt.root -> rc -> rc = new Node(7);
    cout << "The level order traversal is : ";
    bt.level_order_traversal();
    cout << "\nThe preorder traversal is : ";
    bt.pre_order_traversal();
    cout << "\nThe inorder traversal is : ";
    bt.in_order_traversal();
    cout << "\nThe postorder traversal is : ";
    bt.post_order_traversal();
    return 0;
}
