#include <bits/stdc++.h>
using namespace std;

int get_parent_index (int index) {
    if (index <= 0)
        return -1;
    return (index - 1) / 2;
}

void swap (int &a, int &b) {
    a = a + b;
    b = a - b;
    a = a - b;
}

void heapify (vector<int> &heap, int index, int t) {
    int parent_index = get_parent_index (index);
    if (parent_index >= 0) {
        if (t == 0 && heap[index] < heap[parent_index]) {    // min heap         // `t` is a bad solution, but using it for the sake of simplicity
            swap (heap[index], heap[parent_index]);
            heapify (heap, parent_index, t);
        }
        else if (t == 1 && heap[index] > heap[parent_index]) {    // max heap
            swap (heap[index], heap[parent_index]);
            heapify (heap, parent_index, t);
        }
    }
}

void insert_into_heap (vector<int> &heap, int ele, int t) {
    heap.push_back (ele);
    heapify (heap, heap.size() - 1, t);
}

int remove_from_heap (vector<int> &heap, int t) {
    int rem = heap[0];
    heap[0] = heap[heap.size() - 1];
    heap.pop_back();
    heapify (heap, get_parent_index(heap.size()), t);
    return rem;
}

int main() {
    vector<int> maxheap;   // -> 1            // for smaller elements
    vector<int> minheap;   // -> 0            // for larger elements
    while (true) {
        int ele;
        cin >> ele;
        double median;

        if (maxheap.size() > minheap.size()) {
            if (!maxheap.empty() && ele < maxheap[0]) {
                int rem = remove_from_heap (maxheap, 1);   // not a good solution using the last parameter, it's quite error prone, use classes instead for the heaps, also avoids unnecessarily passing the heap as a parameter
                insert_into_heap (minheap, rem, 0);
                insert_into_heap (maxheap, ele, 1);
            }
            else {
                insert_into_heap (minheap, ele, 0);
            }

            int max_top = maxheap.empty() ? 0 : maxheap[0];
            int min_top = minheap.empty() ? 0 : minheap[0];
            median = (max_top + min_top) / 2;
        }
        else if (minheap.size() > maxheap.size()) {
            if (!minheap.empty() && ele > minheap[0]) {
                int rem = remove_from_heap (minheap, 0);
                insert_into_heap (maxheap, rem, 1);
                insert_into_heap (minheap, ele, 0);
            }
            else {
                insert_into_heap (maxheap, ele, 1);
            }

            int max_top = maxheap.empty() ? 0 : maxheap[0];
            int min_top = minheap.empty() ? 0 : minheap[0];
            median = (max_top + min_top) / 2;
        }
        else if (minheap.size() == maxheap.size()) {
            if (!maxheap.empty() && ele <= maxheap[0]) {
                insert_into_heap (maxheap, ele, 1);
                median = maxheap[0];
            }
            else {
                insert_into_heap (minheap, ele, 0);
                median = minheap[0];
            }
        }

        cout << median << endl;
    }
    return 0;
}
