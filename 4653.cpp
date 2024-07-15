#include <bits/stdc++.h>

using namespace std;
int f[5055][5055] = {{0}};int n, a, b;
const long long mod = 1000000007;

//f[i][j] = ((a % mod) * (f[i][j - 1] % mod)) % mod + ((b % mod) * (f[i - 1][j] % mod)) % mod;
signed main() {
    freopen("matrix.in", "r", stdin);
    freopen("matrix.out", "w", stdout);
    memset(f, -1, sizeof(f));
    cin >> n >> a >> b;
    for (int i = 1; i <= n; ++i) {
        cin >> f[i][1];
    }
    for (int i = 1; i <= n; ++i) {
        cin >> f[1][i];
    }
    for (int i = 2; i <= n; ++i) {
        for (int j = 2; j <= n; ++j) {
            f[i][j] = ((a % mod) * (f[i][j - 1] % mod)) % mod + ((b % mod) * (f[i - 1][j] % mod)) % mod;
        }
    }
    cout << f[n][n] % mod << endl;
    return 0;
}

