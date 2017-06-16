#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, W;
    cout << "Enter the number of elements : ";
    cin >> n;
    int wt[n], val[n];
    cout << "Enter the weights and values of the elements : ";
    for (int i=0; i<n; i++)
        cin >> wt[i] >> val[i];
    cout << "Enter the maximum capacity of the knapsack : ";
    cin >> W;
    int dp[n+1][W+1];
    for (int i=0; i<=n; i++)
        for (int j=0; j<=W; j++)
            dp[i][j] = 0;
    for (int i=n-1; i>=0; i--) {
        for (int j=0; j<=W; j++) {
            if (j+wt[i] <= W)
                dp[i][j] = max (val[i] + dp[i+1][j+wt[i]], dp[i+1][j]);
            else
                dp[i][j] = dp[i+1][j];
        }
    }
    cout << "The optimal value of the knapsack is : " << dp[0][0];
    return 0;
}
