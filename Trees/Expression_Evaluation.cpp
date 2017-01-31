#include <iostream>
#include <string>
#include <stack>
using namespace std;

class Node {
    public :
        char info;
        Node* lc;
        Node* rc;
        Node ( char i ) {
            info = i;
            lc = NULL;
            rc = NULL;
        }
        Node() {
            lc = NULL;
            rc = NULL;
        }
};
stack<Node*> s;

Node* createTree ( string expr ) {
    for ( string::iterator it = expr.begin(); it != expr.end(); ++it ) {
        if ( *it == '/' || *it == '*' || *it == '+' || *it == '-' ) {
            Node* s1 = s.top();
            s.pop();
            Node* s2 = s.top();
            s.pop();
            Node* op = new Node(*it);
            op -> lc = s2;
            op -> rc = s1;
            s.push(op);
        }
        else {                     // assuming it is an operand
            Node *n = new Node(*it);
            s.push (n);
        }
    }
    Node* root = s.top();
    return root;
}

void infix ( Node* curr_root ) {
    if (curr_root == NULL) {
        return;
    }
    infix (curr_root -> lc);
    cout << curr_root -> info;
    infix (curr_root -> rc);
}

int main() {
    string expr;
    cout << "Enter the postfix expression (arithmetic only) : ";
    cin >> expr;
    Node *root = createTree( expr );
    cout << "The infix representation is : ";
    infix (root);
    return 0;
}
