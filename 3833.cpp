#include <bits/stdc++.h>
#define int long long
using namespace std;
int a[4005], b[2005];

signed main() {
    freopen("c.in", "r",stdin);
    freopen("c.out", "w",stdout);
    int n, x;
    cin >> n >> x;
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        ans += a[i];
        a[i + n] = a[i];
        b[i] = a[i];
    }
    for (int i = 1; i < n; i++) {
        //cast spells i times
        int tmp = i * x;
        for (int j = 1; j <= n; j++) {
            b[j] = min(b[j], a[j + n - i]);
            tmp += b[j];
        }
        ans = min(ans, tmp);
    }
    cout << ans << endl;
    return 0;
}

