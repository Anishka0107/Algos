#include <iostream>
using namespace std;

void build(int st[], int a[], int start, int end, int num) {
    if (start == end) {
        st[num] = a[start];
        return;
    }
    int mid = (start + end) / 2;
    build(st, a, start, mid, 2*num+1);
    build(st, a, mid+1, end, 2*num+2);
    st[num] = st[2*num+1] + st[2*num+2];
}   

int sum_range(int st[], int lazy[], int start, int end, int l, int r, int num) {
    if (lazy[num] != 0) {
        st[num] += (end-start+1)*lazy[num];    // we have to update each element in start to end range by upd, so we multiply
        if (start != end) {
            lazy[2*num+1] += lazy[num];
            lazy[2*num+2] += lazy[num];
        }
        lazy[num] = 0;
    }
    if (l>end || r<start) 
        return 0;
    else if (l<=start && r>=end)
        return st[num];
    else {
        int mid = (start+end)/2;
        return sum_range(st, lazy, start, mid, l, r, 2*num+1) + sum_range(st, lazy, mid+1, end, l, r, 2*num+2);
    }
}

void update_lazy(int st[], int lazy[], int start, int end, int upd, int l, int r, int num) {
    if(lazy[num] != 0) {
        st[num] += (end-start+1)*lazy[num];
	    if(start != end) {     // not a leaf node
            lazy[2*num+1] += lazy[num];
            lazy[2*num+2] += lazy[num];
        }
        lazy[num] = 0;
    }
    if(l>end || r<start)       // there is no overlap between the update range and start to end
        return;
    if(start>=l && end<=r) {    // complete overlap, so value needs to be updated
        st[num] += (end-start+1)*upd;    
        if(start != end) {
            lazy[2*num+1] += upd;
            lazy[2*num+2] += upd;
        }
        return;
    }
    int mid = (start+end)/2;
    update_lazy(st, lazy, start, mid, upd, l, r, 2*num+1);
    update_lazy(st, lazy, mid+1, end, upd, l, r, 2*num+2);
    st[num] = st[2*num+1] + st[2*num+2];
}

int main() {
    int n;
    cout << "Enter the number of elements : ";
    cin >> n;
    int arr[n];
    cout << "Enter the array elements : ";
    for(int i=0; i<n; i++)
        cin >> arr[i];
    int st[4*n];      // the segment tree, max number of nodes required is 2*n-1
    int lazy[4*n] = {0};         // required for lazy propagation in update 
    build(st, arr, 0, n-1, 0);
    cout << endl;
    cout << "MENU\n\t1. Sum in a range\n\t2. Update a range\n";
    while(true) {
        int ch;
        cout << "Enter your choice : ";
        cin >> ch;
        int left, right;
        cout << "Enter the left and right limits of the range (both inclusive) : ";
        cin >> left >> right;
        switch(ch) {
            case 1: 
                cout << "The required sum is : " << sum_range(st, lazy, 0, n-1, left-1, right-1, 0) << "\n";
                break;
            case 2:
                int upd;
                cout << "Enter the value to be updated with : ";
                cin >> upd;
                update_lazy(st, lazy, 0, n-1, upd, left-1, right-1, 0);
                break;
            default:
                return 0;
        }   
    }
    return 0;
}
