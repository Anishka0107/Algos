#include <iostream>
using namespace std;

void swap (int & x, int & y) {
    int temp = x;
    x = y;
    y = temp;
}

void max_heapify (int arr[], int n) {     // here n is the index of the last child in the heap to be sorted
    int i = (n-1)/2;                      // gets the index of the last parent
    while (i >= 0) {                      // run the loop from last parent till first parent
        int j = 2*i+1;                    // get the index of the left child of current parent
        while (j <= n) {                  // run this loop from the current parent till the last parent, only till adjustments are made (see line 11 and lines 17-18)
            if (j+1 <= n && arr[j+1] > arr[j])       // checking if right exists, if it does and is greater than its left sibling, this becomes the child to be replaced
                j++;
            if (arr[(j-1)/2] < arr[j]) {     // if the parent is smaller than the greater child, we swap it with it; note that it is (j-1)/2 and not i because we get cases where we reuse this enclosing loop for further children of the child which gets swapped and hence needs heapification
                swap (arr[(j-1)/2], arr[j]);
                j = 2*j+1;       // condition to move forward, i.e., we now adjust all the children of the currently swapped child
            }
            else
                break;   // since we haven't made any adjustments, we need not check for violating children, as they already satisfy max heap property due to the fact that we already called max heap for them before doing it for the current parent
        }
        i--;  // decrementing i by 1 for travering all the parents/nodes before n
    }
}

void heap_sort (int arr[], int n) {
    int k = n-1;         // start from the last element (index of last element)
    while (k > 0) {   // only for > 0; for = 0, it is already sorted
        max_heapify (arr, k);   // for each max heapification, from [0,k]
        swap (arr[0], arr[k]);   // exchange last element of heap with first, as first contains the largest element in [0,k]
        k--;          // decrease the size of the heap, now the heap dosen't contain the k_th largest element
    }
}

int main() {
    int n;
    cin >> n;
    int arr[n];
    for (int i=0; i<n; i++)
        cin >> arr[i];
    heap_sort (arr, n);
    for (int i=0; i<n; i++)
        cout << arr[i] << " ";
    return 0;
}
