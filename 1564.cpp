#include <bits/stdc++.h>

using namespace std;
int d[25][25], f[1 << 20][20];

int main() {
    memset(f, 0x3f, sizeof f);
    f[1][0] = 0;
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> d[i][j];
        }
    }
    for (int s = 1; s < (1 << n); ++s) {
        for (int i = 0; i < n; ++i) {
            if (!(s & (1 << i))) continue;
            for (int j = 0; j < n; ++j) {
                if (!(s & (1 << j))) continue;
                if (i == j) continue;
                f[s][i] = min(f[s][i], f[s ^ (1 << i)][j] + d[j][i]);
            }
        }
    }
    int minn = numeric_limits<int>::max();
    for (int i = 0; i < n; ++i) {
        minn = min(minn, f[(1 << n) - 1][i] + d[i][0]);
    }
    cout << minn << endl;
    return 0;
}

