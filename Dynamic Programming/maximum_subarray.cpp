#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    int arr[n];
    for (int i=0; i<n; i++)
        cin >> arr[i];
    int max_sum = INT_MIN, max_incl = 0;
    int start = 0, end = 0, start_incl = 0;
    for (int i=0; i<n; i++) {
        max_incl += arr[i];
        if (max_sum < max_incl) {
            max_sum = max_incl;
            start = start_incl;
            end = i;
        }
        if (max_incl < 0) {
            max_incl = 0;
            start_incl = i+1;
        }
    }
    cout << max_sum;
    cout << "\nStart : " << start << " End : " << end << endl;
    return 0;
}
