#include <iostream>
#define MAX 5
using namespace std;

int arr[MAX];
int front = -1;
int rear = -1;

void insert() {
	if (((front == 0) && (rear == MAX - 1)) || front == rear + 1) {
		cout << "Circular array queue full! Insert operation cannot be performed...\n";
		return;
	}
	int ele;
	cout << "Enter the element to be inserted : ";
	cin >> ele;
	if (rear == -1)
		front = rear = 0;
	else if (rear == MAX - 1)
		rear = 0;
	else
		rear ++;
	arr[rear] = ele;
	cout << "Element " << ele << " inserted!\n";
}

void remove() {
	if (front == -1) {
		cout << "Circular array queue empty! Delete operation cannot be performed...\n";
		return;
	}
	int ele = arr[rear];
	if(rear == front) {
		rear = -1;
		front = -1;
	}
	else if (front == MAX - 1)
		front = 0;
	else
		front ++;
	cout << "Deleted element " << ele <<" successfully!\n";

}

void traverse() {
	if (front == -1) {
		cout << "Circular array queue empty!\n";
		return;
	}
	cout << "The circular array queue is : ";
	if (front <= rear) {
		for (int x = front; x <= rear; x++)
			cout << arr[x] << " ";
	}
	else {
		for (int x = front; x < MAX; x++)
			cout << arr[x] << " ";
		for (int x = 0; x <= rear; x++)
			cout << arr[x] << " ";
	}
	cout << endl;
	}

void search() {
	if (front == -1) {
		cout << "Circular array queue empty! Search operation void...\n";
		return;
	}
	int ele;
	cout << "Enter the element to be searched for : ";
	cin >> ele;
	if (front <= rear) {
		for (int x = front; x <= rear; x++){
			if(ele == arr[x]) {
				cout << "Element found at index " << x <<" of array!\n";
				return;
			}
		}
	}	
	else {
		for (int x = front; x < MAX; x++) {
			if(ele == arr[x]) {
				cout << "Element found at index " << x <<" of array!\n";
				return;
			}
		}
		for (int x = 0; x <= rear; x++) {
			if(ele == arr[x]) {
				cout << "Element found at index " << x <<" of array!\n";
				return;
			}			
		}
	}
	cout << "Sorry! Element not found in list!!\n";
}	

int main() {
	char ch;
	int c;
	do {
		cout << "MENU\n\t1. Insert\n\t2. Delete\n\t3. Traverse\n\t4. Search\n\t5. Exit\nPlease enter your choice : ";
		cin >> c;
		switch(c) {
			case 1:
				insert();
				break;
			case 2:
				remove();
				break;
			case 3:
				traverse();
				break;
			case 4:
				search();
				break;
			case 5:
				return 0;			
			default:
				cout << "Invalid choice entered!\n";
		}
		cout << "Want to continue any further? ";
		cin >> ch;
	} while (ch == 'Y' || ch == 'y');
	return 0;
}