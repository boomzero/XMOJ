#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
typedef long long ll;
ull calc(ll x, ll y, ll d) {
    ull ret = 0;
    if (d <= y) {
        if (d <= x) {
            ret = (d+2)*(d+1)/2;
        } else {
            ret = (d+d-x+2)*(x+1)/2;
        }
    } else if (d-y <= x) {
        ret = (y+1)*(d-y+1);
        if (d >= x) {
            ret += (y + d-x+1) * (x-d+y) / 2;
        } else {
            ret += y*(y+1)/2;
        }
    } else {
        ret += (y+1)*(x+1);
    }
    return ret;
}
ull calc2(ll low, ll high, ll d) {
    ll mini = max(low, -d);
    ll maxi = min(d, high);
    return maxi-mini+1;
}
int main() {
	freopen("manhattan.in", "r", stdin);
	freopen("manhattan.out", "w", stdout);
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll x1, y1, x2, y2, d;
    cin >> x1 >> y1 >> x2 >> y2 >> d;
    ull ans = 0;
    if (y2 >= 0 && x2 >= 0) {
        ll dx = max<ll>(0, x1);
        ll dy = max<ll>(0, y1);
        if (d-dx-dy >= 0) ans += calc(x2-dx, y2-dy, d-dx-dy);
    }
    //cout << ans << endl;
    if (y2 >= 0 && x1 <= 0) {
        ll dx = max<ll>(0, -x2);
        ll dy = max<ll>(0, y1);
        if (d-dx-dy >= 0) ans += calc(-x1-dx, y2-dy, d-dx-dy);
    }
    //cout << ans << endl;
    if (y1 <= 0 && x1 <= 0) {
        ll dx = max<ll>(0, -x2);
        ll dy = max<ll>(0, -y2);
        if (d-dx-dy >= 0) ans += calc(-x1-dx, -y1-dy, d-dx-dy);
    }
    //cout << ans << endl;
    if (y1 <= 0 && x2 >= 0) {
        ll dx = max<ll>(0, x1);
        ll dy = max<ll>(0, -y2);
        if (d-dx-dy >= 0) ans += calc(x2-dx, -y1-dy, d-dx-dy);
    }
    //cout << ans << endl;
    if (x1 <= 0 && 0 <= x2) ans -= calc2(y1, y2, d);
    //cout << ans << endl;
    if (y1 <= 0 && 0 <= y2) ans -= calc2(x1, x2, d);
    //cout << ans << endl;
    if (x1 <= 0 && 0 <= x2 && y1 <= 0 && 0 <= y2) ans--;
    cout << ans << endl;
    return 0;
}
