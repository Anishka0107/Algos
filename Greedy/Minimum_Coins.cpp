#include <iostream>
using namespace std;

// denominations available are 1,2,5,10,20,50,100,500,2000
// the greedy approach works for only this kind of denominations.
int main() {
    int amt;
    cout << "Enter the amount in Rupees : ";
    cin >> amt;
    int deno[9] = {2000, 500, 100, 50, 20, 10, 5, 2, 1};
    cout << "The required coins are : ";
    int ctr = 0;
    while (amt > 0) {
        if (amt >= deno[ctr]) {
            amt -= deno[ctr];
            cout << deno[ctr] << " ";
        }
        else {
            ctr ++;
        }
    }
    return 0;
}