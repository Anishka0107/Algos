#include <bits/stdc++.h>
using namespace std;

int lis (int arr[], int n, int i, int j) {
    if (j >= n)
        return 0;
    int maxim = 0;
    for (int k=j; k<n; k++) {
        if (arr[i] < arr[k])
            maxim = max (maxim, 1 + lis (arr, n, k, k+1));
    }
    return maxim;
}

int main() {
    int n;
    cin >> n;
    int arr[n];
    for (int i=0; i<n; i++)
        cin >> arr[i];
    int maxim = 0;
    for (int i=0; i<n; i++)
        maxim = max (maxim, 1 + lis (arr, n, i, i+1));
    cout << maxim;
    return 0;
}
