#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;    

struct item {
    int weight;
    int value;
    double ratio;
    static bool sorter (const item &i1, const item &i2) {
        return i1.ratio > i2.ratio;
    }
};

int main() {
    int num;
    cout << "Enter the number of items : ";
    cin >> num;
    vector<item> knapsack(num);
    cout << "Enter the items (weight, value) : ";
    for (int i = 0; i < num; i++) {
        cin >> knapsack[i].weight >> knapsack[i].value;
        knapsack[i].ratio = float (knapsack[i].value) / knapsack[i].weight;
    }
    sort (knapsack.begin(), knapsack.end(), item::sorter);
    double capacity, value;
    cout << "Enter the knapsack capacity : ";
    cin >> capacity;
    int i = 0;
    while (capacity >= 0.0 && i < num) {
        if (knapsack[i].weight <= capacity) {
            capacity -= knapsack[i].weight;
            value += knapsack[i].value;
            i++;
        }
        else {
            break;
        }
    }
    if (capacity != 0.0) {
        value += knapsack[i].ratio * capacity;
    }
    cout << "The value of the knapsack is : " << value;
    return 0;
}
