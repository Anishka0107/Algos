#include <bits/stdc++.h>
using namespace std;

// solution in O(n^2) time and O(1) extra space, better than DP which takes O(n^2) time and O(n^2) space
// use some other crazy algo for better time complexity

int main() {
    string s;
    cin >> s;
    int n = s.length();
    int lt, rt, maxlen = 0;
    for (int i=0; i<n-1; i++) {
        for (int p = i-1; p<=i; p++) {
            int left = p, right = i+1;               // p=i-1 corresponds to odd length substrs and p=i for even
            while (left >= 0 && right < n && s[left] == s[right]) {
                left--;
                right++;
            }
            if (maxlen < right-left+1) {
                maxlen = right-left+1;
                rt = right-1;
                lt = left+1;
            }
        }
    }
    cout << lt << " " << rt;
    return 0;
}
