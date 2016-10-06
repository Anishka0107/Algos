#include <iostream>

using namespace std;

struct Node {          // to represent each term of a polynomial 
	float coeff;       // coefficient int the term
	int expo;          // exponent of each term
	Node *next;
};

void add(Node *p1, Node *p2) {
	Node *start = new Node;
	if (p1 -> expo > p2 -> expo) {
		start -> expo = p1 -> expo;
		start -> coeff = p1 -> coeff;
		p1 = p1 -> next; 
	}
	else if (p1 -> expo < p2 -> expo) {
		start -> expo = p2 -> expo;
		start -> coeff = p2 -> coeff;
		p2 = p2 -> next; 
	}
	else {         // equal exponents
		start -> coeff = p1 -> coeff + p2 -> coeff;
		start -> expo = p1 -> expo;
		p1 = p1 -> next;
		p2 = p2 -> next;
	}
	start -> next = NULL;
	Node *curr = start;
	Node *prev = start;
	while ((p1 != NULL) && (p2 != NULL)) {
		curr = new Node;
		prev -> next = curr;
		curr -> next = NULL;
		if (p1 -> expo > p2 -> expo) {
			curr -> coeff = p1 -> coeff;
			curr -> expo = p1 -> expo;
			p1 = p1 -> next;
		}
		else if (p1 -> expo < p2 -> expo) {
			curr -> coeff = p2 -> coeff;
			curr -> expo = p2 -> expo;
			p2 = p2 -> next;
		}
		else {                           // equal exponents
			curr -> coeff = p1 -> coeff + p2 -> coeff;
			curr -> expo = p1 -> expo;
			p1 = p1 -> next;
			p2 = p2 -> next;
		}
		prev = prev -> next;
	}
	while (p1 != NULL) {
		curr = new Node;
		prev -> next = curr;
		curr -> next = NULL;
		curr -> coeff = p1 -> coeff;
		curr -> expo = p1 -> expo;
		p1 = p1 -> next;
		prev = prev -> next;		
	}
	while (p2 != NULL) {
		curr = new Node;
		prev -> next = curr;
		curr -> next = NULL;
		curr -> coeff = p2 -> coeff;
		curr -> expo = p2 -> expo;
		p2 = p2 -> next;
		prev = prev -> next;		
	}
	Node *trav = start;
	while (trav -> next != NULL) {
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
	cout << "The sum of the two polynomials is : ";
	add(p1, p2);
	return 0;
}