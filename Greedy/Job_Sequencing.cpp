#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

struct job {
    int id;
    int profit;
    int deadline;
    static bool sorter (const job &j1, const job &j2) {
        return j1.profit > j2.profit;
    }
};

int main() {
    int n;
    cout << "Enter the number of jobs : ";   
    cin >> n;
    vector<job> jv(n);
    vector<int> results;
    int jobsdone[n] = {0};    
    cout << "Enter the id, profit and deadline of the jobs respectively : ";
    for (int i = 0; i < n; i++) {
        cin >> jv[i].id >> jv[i].profit >> jv[i].deadline;
    }
    sort (jv.begin(), jv.end(), job::sorter);
    results.push_back (jv[0].id);
    jobsdone[jv[0].deadline - 1] = 1;
    for (int i = 1; i < n; i++) {
        for (int j = jv[i].deadline - 1; j >= 0; j--) {
            if (jobsdone[j] == 0) {
                results.push_back (jv[i].id);
                jobsdone[j] = 1;
                break;
            }
        }
    }
    for (int i = 0; i < results.size(); i++) {
        cout << results[i] << " ";
    }
    return 0;
}