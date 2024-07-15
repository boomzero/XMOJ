#include <bits/stdc++.h>

using namespace std;

int main() {
    freopen("square.in", "r", stdin);
    freopen("square.out", "w", stdout);
    int n, ans = 0;
    cin >> n;
    for (int i = 0; i * i <= n; i++) {
        for (int j = 0; j * j <= n - i * i; ++j) {
            for (int k = 0; k * k <= n - i * i - j * j; ++k) {
                int h = ((int) sqrt(n - i * i - j * j - k * k) + 0.01);
                if (h * h == n - i * i - j * j - k * k) {
                    ans++;
                    clog << i * i << " " << j * j << " " << k * k << " " << n - i * i - j * j - k * k << endl;
                }
            }
        }
    }
    cout << ans << endl;
    return 0;
}
