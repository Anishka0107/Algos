#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct activity {
    int start;
    int finish;
    static bool sorter (const activity &a1, const activity &a2) {
        return a1.finish < a2.finish;
    }
};

int main() {
    int n;
    cout << "Enter the number of activities : ";
    cin >> n;
    vector<activity> av(n);
    cout << "Enter the start times of the activities : ";
    for (int i = 0; i < n; i++) {
        cin >> av[i].start;
    }
    cout << "Enter the finish times of the activities : ";
    for (int i = 0; i < n; i++) {
        cin >> av[i].finish;
    }
    int prevfinish;
    sort(av.begin(), av.end(), activity::sorter);
    cout << "Activity : " << av[0].start << " " << av[0].finish << endl;
    prevfinish = av[0].finish;
    for (int i = 1; i < n; i++) {
        if (av[i].start > prevfinish) {
            cout << "Activity : " << av[i].start << " " << av[i].finish << endl;        
            prevfinish = av[i].finish;
        }
    }
    return 0;
}