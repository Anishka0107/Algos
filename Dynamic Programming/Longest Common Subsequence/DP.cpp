#include <iostream>
using namespace std;

int max (int a, int b) {
	return a>b?a:b;
}
int main() {
	int n1, n2;
	cout << "Enter the number of elements in the first sequence : ";
	cin >> n1;
	cout << "Enter the number of elements in the second sequence : ";
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
	int lookup[n1+1][n2+1];
	for (int i=0; i<=n1; i++) {
		for (int j=0; j<=n2; j++){
			if (i == 0 || j == 0) {
				lookup[i][j] = 0;
			}
			else if (arr1[i-1] == arr2[j-1]) {
				lookup[i][j] = lookup[i-1][j-1] + 1;			
			}
			else {
				lookup[i][j] = max (lookup[i-1][j], lookup[i][j-1]);
			}
		}
	}
	cout << "The length of the longest common subsequence is : " << lookup[n1][n2];
	int idx=lookup[n1][n2]-1, i=n1, j=n2, lcs[lookup[n1][n2]];
	while (i>0 && j>0) {
		if (arr1[i-1] == arr2[j-1]) {
			lcs[idx] = arr1[i-1];
			i--;
			j--;
			idx--;
			continue;
		}
		if (lookup[i-1][j] > lookup[i][j-1]) {
			i--;
		}
		else {
			j--;
		}

	}
	cout << "\nThe longest common subsequence is : ";
	for (int i=0; i<lookup[n1][n2]; i++) {
		cout << lcs[i] << " ";
	}
	return 0;
}
