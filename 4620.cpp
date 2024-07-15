#include <bits/stdc++.h>

using namespace std;

int main() {
    freopen("game.in", "r", stdin);
    freopen("game.out", "w", stdout);
    int n, m, mid;
    cin >> n >> m;
    if (n == 1) {
        cout << 1 << endl;
        return 0;
    }
    if (n % 2) mid = (n+1) / 2;
    else mid = n / 2;
    if (m < mid) cout << m + 1 << endl;
    else cout << m - 1 << endl;
    return 0;
}

