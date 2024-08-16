#include <bits/stdc++.h>

using namespace std;

int main() {
    freopen("candy.in", "r", stdin);
    freopen("candy.out", "w", stdout);
    int n, l, r;
    cin >> n >> l >> r;
    if (r / n == l / n) {
        cout << r % n << endl;
    } else {
        cout << n - 1 << endl;
    }
    return 0;
}
