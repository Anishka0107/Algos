#include <bits/stdc++.h>
using namespace std;

int knapsack (int w, int wt[], int val[], int W, int i, int n) {
    if (i == n)
        return 0;
    if (w+wt[i] > W)
        return knapsack (w, wt, val, W, i+1, n);
    return max (val[i] + knapsack (w+wt[i], wt, val, W, i+1, n), knapsack (w, wt, val, W, i+1, n));
}

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
    cout << "The optimal value of the knapsack is : " << knapsack (0, wt, val, W, 0 ,n);
    return 0;
}
