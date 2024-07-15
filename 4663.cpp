#include <bits/stdc++.h>

using namespace std;

int gcd(int a, int b) { return b == 0 ? a : gcd(b, a % b); }

int main() {
    freopen("ad.in", "r", stdin);
    freopen("ad.out", "w", stdout);
    int p;
    cin >> p;
    cout << 100 / gcd(p, 100) << endl;
    return 0;
}

