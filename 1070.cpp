#include <bits/stdc++.h>
using namespace std;
int l, n, m;
int d[50005] = {0};
bool check(int x) {
    int i = 0, t = 0, fl = 1;
    while (i <= n) {
        if (d[i + fl] - d[i] < x) {
            t++;
            fl++;
            if (i + fl > n) break;
        } else {
            i += fl;
            fl = 1;
        }
    }
    return t <= m;
}
int main() {
    cin >> l >> n >> m;
    for (int i = 1; i <= n; ++i) {
        cin >> d[i];
    }
    d[n + 1] = l;
    int lb = 1, rb = l;
    int c;
    while (lb < rb) {
        c = (lb + rb) / 2;
        if (!check(c)) {
            rb = c;
        } else {
            lb = c + 1;
        }
    }
    c = check(c + 1) ? c + 1 : check(c) ? c : c - 1;
    cout << c << endl;
    return 0;
}
