#include <bits/stdc++.h>
using namespace std;

int lps (int i, int j, int arr[]) {
    if (i == j)
        return 1;
    if (i > j)
        return 0;
    if (arr[i] == arr[j])
        return 2 + lps (i+1, j-1, arr);
    return max (lps (i+1, j ,arr), lps (i, j-1, arr));
}

int main() {
    int n;
    cin >> n;
    int arr[n];
    for (int i=0; i<n; i++)
        cin >> arr[i];
    cout << lps (0, n-1, arr);
    return 0;
}
