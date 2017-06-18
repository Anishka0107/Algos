#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    int arr[n];
    for (int i=0; i<n; i++)
        cin >> arr[i];
    int dp[n];
    for (int i=0; i<n; i++)
        dp[i] = 1; 
    for (int i=n-1; i>=0; i--) {
        int maxim = 1;
        for (int j=i+1; j<n; j++)
            if (arr[i] < arr[j])
                maxim = max (maxim, 1 + dp[j]);
        dp[i] = maxim;
    }
    int maxim = dp[0];
    for (int i=1; i<n; i++)
        maxim = max (maxim, dp[i]);
    cout << maxim;
    return 0;
}
