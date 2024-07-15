#include <bits/stdc++.h>

using namespace std;
typedef unsigned long long ll;

ll qpow(ll base, ll pow, ll mod) {
    ll rst = 1;
    while (pow > 0) {
        if (pow & 1) {
            rst = rst * (base % mod) % mod;
        }
        pow >>= 1;
        base %= mod;
        base *= base;
        base %= mod;
    }
    return rst % mod;
}

int main() {
    long long n;
    cin >> n;
    cout << qpow(2, n - 1, 1000000007) << endl;
    return 0;
}

