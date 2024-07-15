#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, v, c[600] = {0}, w[600] = {0}, s[600] = {0};
    int f[20001] = {0};
    cin >> v >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> s[i] >> c[i] >> w[i];
    }
    memset(f, 0, sizeof(f));
    for (int i = 1; i <= n; ++i) {
        for (int j = v; j >= c[i]; --j) {
            for (int k = 1; k <= s[i]; ++k) {
                if (j - k * c[i] >= 0)
                    f[j] = max(f[j], f[j - k * c[i]] + k * w[i]);
            }
        }
    }
    cout << f[v] << endl;
    return 0;
}

