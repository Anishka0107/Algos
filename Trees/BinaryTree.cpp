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
	void level_order_traversal();         // basically BFS
	void pre_order_traversal(Node*);      // basically DFS  
	void in_order_traversal(Node*);       // basically DFS
	void post_order_traversal(Node*);     // basically DFS
	int depth(Node*);
	int curr_level_width(Node*, int);
	int max_width();
	int search(Node*, int);
	int ancestors(Node*,int);
	void print_level(Node*,int);
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
	if (front -> x -> lc != NULL) {
	    ex = new Extra;
	    ex -> x = front -> x -> lc;
	    insert(ex);
	}
	if (front -> x -> rc != NULL) {
        ex = new Extra;
	    ex -> x= front -> x -> rc;
	    insert(ex);
	}
	remove();
    }
}

void BinaryTree :: pre_order_traversal (Node *curr_root) {
    if (curr_root == NULL) {
        return;
    }
    cout << curr_root -> info << " ";
    pre_order_traversal (curr_root -> lc);
    pre_order_traversal (curr_root -> rc);
}

void BinaryTree :: in_order_traversal (Node* curr_root) {
    if (curr_root == NULL) {
        return;
    }
    in_order_traversal (curr_root -> lc);
    cout << curr_root -> info << " ";
    in_order_traversal (curr_root -> rc);
}

void BinaryTree :: post_order_traversal (Node* curr_root) {
    if (curr_root == NULL) {
        return;
    }
    post_order_traversal (curr_root -> lc);
    post_order_traversal (curr_root -> rc);
    cout << curr_root -> info << " ";
}

int BinaryTree :: depth (Node *curr_root) {
    if (curr_root == NULL) {
        return 0;
    }
    int d1 = 1 + depth (curr_root -> rc);
    int d2 = 1 + depth (curr_root -> lc);
    int d = d1 > d2 ? d1 : d2;
    return d;
}

int BinaryTree :: curr_level_width (Node* curr_root, int level) {
    if (curr_root == NULL){
        return 0;
    }
    if (level == 1) {
        return 1;
    }
    return curr_level_width (curr_root->lc, level-1) + curr_level_width (curr_root->rc, level-1);
}

int BinaryTree :: max_width () {
    int maxwidth = 0, width;
    for (int i = 1; i <= depth(root); i++) {
        width = curr_level_width(root, i);
        if (width > maxwidth) {
            maxwidth = width;
        }
    }
    return maxwidth;
}

int BinaryTree :: search (Node* curr_root, int ele) {
    if (curr_root == NULL) {
        return 0;
    }
    if (curr_root -> info == ele) {
        return 1;
    }
    else {
        int  i = search (curr_root -> lc, ele);
        int j = search (curr_root -> rc, ele);
        if (i == 1 || j == 1) {
            return 1;
        }
        else {
            return 0;
        }
    }
}

int BinaryTree :: ancestors (Node* curr_root, int ele) {
    if (curr_root == NULL) {
        return 0;
    }
    if (curr_root -> info == ele) {
        return 1;
    }
    if (ancestors(curr_root->lc,ele) || ancestors(curr_root->rc,ele)) {
        cout << curr_root -> info << " ";
        return 1;
    }
    return 0;
}

void BinaryTree :: print_level (Node* curr_root, int level) {
    if (curr_root == NULL) {
        return;
    }
    else if (level == 1) {
        cout << curr_root -> info << " ";
    }
    else {
        print_level (curr_root -> lc, level-1);
        print_level (curr_root -> rc, level-1);
    }
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
    bt.root -> lc -> lc -> rc= new Node(8);
    bt.root -> lc -> lc -> rc -> rc = new Node(9);
    bt.root -> lc -> lc -> rc -> rc -> lc = new Node(10);
    bt.root -> lc -> lc -> rc -> rc -> lc -> rc= new Node(11);
    cout << "The level order traversal is : ";
    bt.level_order_traversal();
    cout << "\nThe preorder traversal is : ";
    bt.pre_order_traversal (bt.root);
    cout << "\nThe inorder traversal is : ";
    bt.in_order_traversal (bt.root);
    cout << "\nThe postorder traversal is : ";
    bt.post_order_traversal (bt.root);
    cout << "\nThe depth of the tree is : " << bt.depth (bt.root);
    cout << "\nThe maximum width of the tree is : " << bt.max_width ();
    int k;
    cout << "\nEnter any node to be searched for : ";
    cin >> k;
    int idx = bt.search (bt.root, k);
    if (idx == 1) {
        cout << "Element found!";
        cout << "\nThe ancestors of the node " << k << " are : ";
        bt.ancestors (bt.root, k);
    }
    else {
        cout << "Element not found!!";
    }
    cout << "\nEnter a level. It's nodes will be printed : ";
    cin >> k;
    if (k > bt.depth (bt.root)) {
        cout << "Level does not exist!!";
    }
    else {
        bt.print_level (bt.root, k);
    }
    return 0;
}
