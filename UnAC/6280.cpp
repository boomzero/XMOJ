#include <bits/stdc++.h>
#define int long long
using namespace std;
signed main() {
    freopen("decode.in", "r", stdin);
    freopen("decode.out", "w", stdout);
    int k;
    cin >> k;
    for (int i = 0; i < k; ++i) {
        int n, e, d, p = 0, q = 0;
        cin >> n >> e >> d;
        int delta = floor(sqrt((e * d - n - 2) * (e * d - n - 2) - 4 * n) + 0.1);
        if ((-(e * d - n - 2) - delta) % 2 == 1 ||
            (e * d - n - 2) * (e * d - n - 2) - 4 * n < 0) {
            cout << "NO" << endl;
            continue;
        }
        int p1 = (-(e * d - n - 2) - delta) / 2;
        int p2 = (-(e * d - n - 2) + delta) / 2;
        p = p1 < p2 ? p1 : p2;
        q = n / p1;
        if (p2 + q == -e * d + n + 2 && p2 < q) {
            q = n / p2;
            cout << p2 << " " << q << endl;
        } else if (p1 + q == -e * d + n + 2) {
            cout << p1 << " " << q << endl;
        } else {
            cout << "NO" << endl;
        }
    }
    return 0;
}
