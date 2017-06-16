#include <iostream>
using namespace std;

int main() {
	int tot, num;
	cout << "Enter the total amount : ";
	cin >> tot;
	cout << "Enter the number of values of coins present : ";
	cin >> num;
	int coin[num];
	cout << "Enter the values of the coins : ";
	for (int i=0; i<num; i++)
		cin >> coin[i];
    int dp[tot+1][num+1] = {0};
    for (int i=0; i<=num; i++)
        dp[0][i] = 1;
    for (int i=1; i<=tot; i++) {
        for (int j=1; j<=num; j++) {
            dp[i][j] = dp[i][j-1];
            if (i-coin[j-1] >= 0)
                dp[i][j] += dp[i-coin[j-1]][j];
        }
    }
	cout << "The number of ways in which we can generate the total amount from an infinite supply of the provided coins is : " << dp[tot][num];
	return 0;
}

