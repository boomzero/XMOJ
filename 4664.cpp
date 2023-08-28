#include <bits/stdc++.h>

using namespace std;

int tp(int n) {
    int ans = 1;
    for (int i = 1; i <= n; ++i) {
        ans *= 2;
    }
    return ans;
}

int main() {
    freopen("bend.in", "r", stdin);
    freopen("bend.out", "w", stdout);
    int k, m;
    cin >> k >> m;
    int st = 0;
    for (int i = 1; i <= m; ++i) {
        int op;
        cin >> op;
        if (op == 0) st++;
        else {
            int x1, y1, x2, y2;
            cin >> x1 >> y1 >> x2 >> y2;
            int cv = tp(k - st);
            if ((x1 % cv == 0 && x1 < x2 ) || (y1 % cv == 0 && y1 < y2 )) {
                cout << 1 << endl;
            } else if ((y2 < y1 && x1 == x2) || (x2 < x1 && y1 == y2)) {
                swap(x1, x2);
                swap(y1, y2);
                if ((x1 % cv == 0 && x1 != x2) || (y1 % cv == 0 && y1 != y2)) {
                    cout << 1 << endl;
                } else {
                    cout << 0 << endl;
                }
            } else {
                cout << 0 << endl;
            }
        }
    }
    return 0;
}

