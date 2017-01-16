#include <iostream>
using  namespace std;

int num_ways (int coin[], int sum, int num) {
	if (sum < 0) {
		return 0;
	}
	if (sum == 0) {
    		return 1;
	}
	if (num <= 0) {
		return 0;
	}
	return num_ways (coin, sum, num-1) + num_ways (coin, sum-coin[num-1], num);
}

int main() {
	int tot, num;
	cout << "Enter the total amount : ";
	cin >> tot;
	cout << "Enter the number of values of coins present : ";
	cin >> num;
	int coin[num];
	cout << "Enter the values of the coins : ";
	for (int i=0; i<num; i++) {
		cin >> coin[i];
	}
	cout << "The number of ways in which we can generate the total amount from an infinite supply of the provided coins is :  " << num_ways(coin, tot, num);
	return 0;
}

