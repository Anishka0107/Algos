#include <iostream>
using namespace std;

int max (int a, int b) {
    return a>b ? a : b;
}
int main() {
    int n;
    cout << "Enter the length of rod : ";
    cin >> n;
    int arr[n];
    cout << "Enter the prices of the rod : ";
    for (int i=0; i<n; i++)
        cin >> arr[i];
    int dp[n+1];
    dp[0] = 0;
    for (int i=1; i<=n; i++) {
        int maxim = arr[i-1];
        for (int j=1; j<i; j++)
            maxim = max (maxim, dp[j] + arr[i-1-j]);
        dp[i] = maxim;
    }
    cout << "The maximum revenue that can be generated is : " << dp[n];
    return 0;
}
