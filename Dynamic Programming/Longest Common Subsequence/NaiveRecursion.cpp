#include <iostream>
using namespace std;

int max (int a, int b) {
	return a>b?a:b;
}

int LCS (int arr1[], int n1, int arr2[], int n2) {
	if (n1 == 0 || n2 == 0) {
		return 0;
	}	
	if (arr1[n1-1] == arr2[n2-1]) {
		return 1 + LCS (arr1, n1-1, arr2, n2-1);
	}
	return max (LCS (arr1, n1-1, arr2, n2), LCS (arr1, n1, arr2, n2-1));
}

int main() {
	int n1, n2;
	cout << "Enter the number of numbers in first sequence : ";
	cin >> n1;
	cout << "Enter the number of numbers in second sequence : ";
	cin >> n2;
	int arr1[n1], arr2[n2];
	cout << "Enter the elements of the first sequence : ";
	for (int i=0; i<n1; i++) {
		cin >> arr1[i];
	}
	cout << "Enter the elements of the second sequence : ";
	for (int i=0; i<n2; i++) {
		cin >> arr2[i];
	}
	cout << "The length of the longest common subsequence is : " << LCS (arr1, n1, arr2, n2);
	return 0;
}
