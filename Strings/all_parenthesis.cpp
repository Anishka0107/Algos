#include <bits/stdc++.h>
using namespace std;

void bal_par (string p, int n_op, int n_cl) {
    if (n_op == -1)
        return;
    if (n_cl == 0) {
        cout << p << endl;
        return;
    }
    bal_par (p+"{", n_op-1, n_cl);
    if (n_op < n_cl)
        bal_par (p+"}", n_op, n_cl-1);
}

int main() {
    int n;
    cin >> n;
    string s = "{";
    bal_par (s, n-1, n);
    return 0;
}
