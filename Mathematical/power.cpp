#include <bits/stdc++.h>
#define ll long long
using namespace std;

ll power (ll base, ll exponent) {
    if (exponent == 0)
        return 1;
    ll power = base, exp = 1;
    while (exp*2 <= exponent) {
        power *= power;
        exp *= 2;
    }
    while (exp < exponent) {
        power *= base;
        exp++;
    }
    return power;
}

int main() {
    ll base, exponent;
    cin >> base >> exponent;
    cout << power (base, exponent);
    return 0;
}
