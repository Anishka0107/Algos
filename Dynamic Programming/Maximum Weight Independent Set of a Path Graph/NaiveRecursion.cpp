#include <iostream>
using namespace std;

int max (int a, int b) {
    return a>b?a:b;
}

int vert (int arr[], int n) {
    if (n == -1) {
	return 0;
    }
    if (n == 0) {
        return arr[0];
    }
    else {
	return max (vert(arr, n-1), vert(arr, n-2)+arr[n]);
    }
}

int main() {
	int n;
	cout << "Enter the number of vertices in the path graph : ";
	cin >> n;
	int g[n];
	cout << "Enter the vertices of the graph : ";
	for (int i=0; i<n; i++) {
	    cin >> g[i];
	}
	cout << "The maximum weighted independent set sum is : " << vert(g,n-1);
	return 0;
}
