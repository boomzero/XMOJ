#include <bits/stdc++.h>

using namespace std;
int n, rd[100005], bcnt = 2, ans;

int main() {
    freopen("road.in", "r", stdin);
    freopen("road.out", "w", stdout);
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> rd[i];
    }
    for (int i = 2; i <= n; i++) {
        if (rd[i] > rd[i - 1])
            ans += rd[i] - rd[i - 1];
    }
    cout << ans + rd[1] << endl;
    return 0;
}

