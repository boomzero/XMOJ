#include <bits/stdc++.h>

#define int long long
using namespace std;

signed main() {
    int n, z, w;
    cin >> n >> z >> w;
    int a[2005] = {0};
    for (int i = 0; i < n; ++i) {
        cin >> a[i + 1];
    }
    if (n == 1) {
        cout << abs(a[n] - w) << endl;
    } else {
        cout << max(abs(a[n] - w), abs(a[n] - a[n - 1]));
    }
    return 0;
}

