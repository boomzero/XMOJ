#include <bits/stdc++.h>
using namespace std;
int n, p[2001] = {0}, f[2001] = {0}, c;
int cut(int l) {
    if (l == 0) return c;
    if (f[l] > 0) return f[l];
    for (int i = 1; i <= l; ++i) {
        f[l] = max(f[l], cut(l - i) + p[i] - c);
    }
    return f[l];
}
int main() {
    fill_n(p, 2000, -1);
    cin >> n >> c;
    for (int i = 1; i <= n; ++i) {
        cin >> p[i];
    }
    cout << cut(n) << endl;
    return 0;
}
