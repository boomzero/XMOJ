#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main() {
    freopen("remote.in", "r", stdin);
    freopen("remote.out", "w", stdout);
    ll x, y, l, ans = 0;
    cin >> x >> y >> l;
    if (y < 0) ans += 2;
    else if (x != 0) ans++;
    ans += abs(x) / l;
    if (abs(x) % l > 0) ans++;
    ans += abs(y) / l;
    if (abs(y) % l > 0) ans++;
    cout << ans << endl;
    return 0;
}
