#include <iostream>

using namespace std;

struct Node {          // to represent each term of a polynomial 
	float coeff;       // coefficient int the term
	int expo;          // exponent of each term
	Node *next;
};

void multiply(Node *p1, Node *p2) {
	Node *start = new Node;
    Node *subs = p2;
    Node *curr = start;
    curr -> next = NULL;
    while (p1 -> next != NULL) {
        while(p2 != NULL) {
            curr -> expo = p1 -> expo + p2 -> expo;
            curr -> coeff = p1 -> coeff * p2 -> coeff;
            curr -> next = new Node;
            curr = curr -> next;
            p2 = p2 -> next;
        }
        p2 = subs;
        p1 = p1 -> next;
    }
    while(p2 -> next != NULL) {
            curr -> expo = p1 -> expo + p2 -> expo;
            curr -> coeff = p1 -> coeff * p2 -> coeff;
            curr -> next = new Node;
            curr = curr -> next;
            p2 = p2 -> next;
        }
    curr -> coeff = p2 -> coeff * p1 -> coeff;
    curr -> expo = p2 -> expo + p1 -> expo;
    curr -> next = NULL;

    Node *newlist = new Node;
    curr = start;
    Node *tert = newlist;
    int bigexpo = start -> expo;
    while (bigexpo >= 0) {
        newlist -> expo = bigexpo;
        newlist -> coeff = 0;
        while (curr != NULL) {
            if (bigexpo == curr -> expo) {
                newlist -> coeff += curr -> coeff;  
            }
            curr = curr -> next;
        }
        newlist -> next = new Node;
        newlist = newlist -> next;
        curr = start;
        bigexpo --;
    }
    
	Node *trav = tert;
	while (trav -> next -> next != NULL) {
        if (trav -> coeff != 0)
            cout << trav -> coeff << "*x^" << trav -> expo << " + ";
		trav = trav -> next;
    }
        cout << trav -> coeff << "*x^" << trav -> expo << endl;
}

Node* getpolynomial() {
	char ch;
	Node *start = NULL;
	Node *prev; 
	cout << "Please enter the polynomial in the descending order of exponents\n";
	do {
			Node* n = new Node;
			n -> next = NULL;
			cout << "Enter the coefficient : ";
			cin >> n -> coeff;
			cout << "Enter the exponent : ";
			cin >> n -> expo;
			if (start == NULL) {    //stupid extra overhead of comparing each time, but im lazy so im not writing it outside! 
				start = n;
				prev = start;
			}
			else {
				prev -> next = n;
				prev = prev -> next;
			}
			cout << "Do you want to enter any more terms : ";
			cin >> ch;

	} while (ch == 'y' || ch == 'Y');
	cout << "The polynomial which you entered is (in terms of 'x') : ";
	Node *trav = start;
	while (trav -> next != NULL) {
		cout << trav -> coeff << "*x^" << trav -> expo << " + ";
		trav = trav -> next;
	}
	cout << trav -> coeff << "*x^" << trav -> expo << endl;
	return start;
}

int main() {
	Node *p1,*p2;
	cout << "Enter first polynomial\n";
	p1 = getpolynomial();
	cout << "Enter second polynomial\n";
	p2 = getpolynomial();
	cout << "The product of the two polynomials is : ";
	multiply(p1, p2);
	return 0;
}