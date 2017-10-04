#include <bits/stdc++.h>
#define ll long long
using namespace std;

ll power (ll base, ll exponent) {
    ll ans = 1 , fact = base;
    while(exponent){
        if(exponent%2==1)
            ans = ans * fact ;
        fact = fact * fact ;
        exponent = exponent/2;
    }
    return ans;
}

int main() {
    ll base, exponent;
    cin >> base >> exponent;
    cout << power (base, exponent);
    return 0;
}
