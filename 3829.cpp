#include <bits/stdc++.h>

using namespace std;

int main() {
    freopen("a.in", "r", stdin);
    freopen("a.out", "w", stdout);
    int n, t;
    cin >> n >> t;
    int minc = -1;
    for (int i = 0; i < n; ++i) {
        int tc, tt;
        cin >> tc >> tt;
        if (tt <= t && (minc == -1 || minc > tc)) {
            minc = tc;
        }
    }
    if (minc == -1) cout << "TLE" << endl;
    else cout << minc << endl;
    return 0;
}
