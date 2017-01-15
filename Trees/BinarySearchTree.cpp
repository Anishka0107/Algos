#include <iostream>
using namespace std;

class Node {
    public:
        int info;
	Node* lc;
	Node* rc;
        Node(int ele) {
	    lc = NULL:
	    rc = NULL;
	    info = ele;
	}
};

class BinarySearchTree {
    public:
	Node* root;
	BinaryTree() {
	    root = NULL;	
	}
        int search(int);
	void insert(int);
        int remove(int);
};

int BinarySearchTree :: search (int ele) {

}

void BinarySearchTree :: insert (int ele) {

}

int BinarySearchTree :: remove(int ele) {

}

int main() {
    char ch;
    int c;
    BinarySearchTree bst;
    cout << "MENU :\n1.Insert\n2.Delete\n3.Search";
    do {
        cout << "Enter the operation which you wish to perform : ";
	cin >> c;
	switch (c) {
	    case 1: 
		int ele;
		cout << "Enter the element to be inserted : ";
		cin >> ele;
		bst.insert(ele);
		break;
	    case 2:
		int ele;
		cout << "Enter the element to be deleted : ";
		cin >> ele;
		bst.remove(ele);
		break;
	    case 3:
		int ele;
		cout << "Enter the element to be searched for : ";
		cin >> ele;
		bst.search(ele);
		break;
	    default:
		cout << "Wrong choice entered!!";
	}
	cout << "Do you wish to continue : ";
	cin >> ch;
    } while (ch == "Y" || ch == "y");
    return 0;
}
