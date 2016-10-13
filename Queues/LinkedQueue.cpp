#include <iostream>
using namespace std;

struct Node {
	int info;
	Node *next;
};

class Queue {
	public:
	Node *front;
	Node *rear;
	Queue() {
		front = NULL;
		rear = NULL;
	}
	void add();
	void remove();
	void traverse();
	void search();
};

void Queue::add() {
	int x;
	cout << "Enter the element you want to insert into the queue : ";
	cin >> x;
	Node *newnode = new Node();
	newnode -> info = x;
	newnode -> next = NULL;
	if(front == NULL) {
		front = newnode;
		rear = newnode;
		return;
		}
	rear -> next = newnode;
	rear = newnode;	
}

void Queue::remove() {
	if(rear == NULL) {
		cout << "Queue empty!!\n";
		return;
	}
	if (front == rear) {
		delete rear;
		front = NULL;
		rear = NULL;
		return;
	}
	int x = rear -> info;
	Node *curr = front;
	while (curr -> next -> next != NULL) { 
		curr = curr -> next; 
	}
	rear = curr;
	curr = curr -> next;
	delete curr;
	rear -> next = NULL;
	cout << "Deleted element " << x << endl;
}

void Queue::traverse() {
	if (front == NULL) {
		cout << "Queue empty!!\n";
		return;
	}
	Node *ptr = front;
	while (ptr != rear -> next) {
		cout << ptr -> info << "  ";
		ptr = ptr -> next;
	}
	cout << endl;
}

void Queue::search() {
	if (front == NULL)
	{
		cout << "Queue empty!!" << endl;
		return;
	}
	int ele;
	cout << "Enter the element you want to search for : ";
	cin >> ele;
	Node *check = front;
	int i=1;
	while (check != rear -> next) {
		if (ele == check -> info) {
			cout << "Element found at position : " << i << endl;
			return;
		}
		check = check -> next;
		i++;
	}
	cout << "Element not found in the linked list!!\n";
}

int main() {
	Queue q;
	char ch;
	int i;
	do {
		cout<<"MENU\n1.Add element\n2.Remove element\n3.Traverse Queue\n4.Search for an element\nEnter your choice : ";
		cin>>i;
		switch(i) {
			case 1:
				q.add();
				break;
			case 2:
				q.remove();
				break;
			case 3:
				q.traverse();
				break;
			case 4:
				q.search();
				break;
			default:
				cout<<"Invalid choice entered!\n";
		}
		cout<<"Do you want to continue? ";
		cin>>ch;
		cout << endl;
	} while(ch=='Y' || ch=='y');
	return 0;
}
