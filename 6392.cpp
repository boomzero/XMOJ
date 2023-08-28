#include <bits/stdc++.h>

using namespace std;

int main() {
    freopen("card.in", "r", stdin);
    freopen("card.out", "w", stdout);
    long long w, h, n;
    cin >> w >> h >> n;
    set<long long> wc, hc;
    for (int i = 0; i < n; ++i) {
        long long x, y;
        cin >> x >> y;
        wc.insert(x);
        hc.insert(y);
    }
    cout << w * h - (w - wc.size()) * (h - hc.size()) - n << endl;
    return 0;
}
