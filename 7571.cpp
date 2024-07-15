#include <bits/stdc++.h>

using namespace std;
int b[505];

int main() {
    freopen("pyramid.in","r",stdin);
    freopen("pyramid.out","w",stdout);
    int n;
    cin >> n;
    int tot = 0;
    for (int i = 1; i <= n; ++i) {
        cin >> b[i];
        tot += b[i];
    }
    int ans = numeric_limits<int>::max(), cans = 0;
    for (int i = 1; i <= 200; i++) {
        int req = (1 + i) * i / 2 + i * (i - 1) / 2;
        cans = 0;
        if (req > tot)
            continue;
        for (int j = 1; j <= i; j++) {
            if (b[j] > j) {
                cans += b[j] - j;
            }
        }
        for (int j = i - 1, pos = i + 1; j > 0; j--, pos++) {
            if (b[pos] > j) {
                cans += b[pos] - j;
            }
        }
        for (int j = i * 2; j <= n; ++j) {
            cans += b[j];
        }
        ans = min(ans, cans);
    }
    cout << ans << endl;
    return 0;
}

