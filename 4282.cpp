#include <bits/stdc++.h>

using namespace std;
int d[100005], ans;

int main() {
    int n;
    cin >> n;
    for (int i = 1; i < n; ++i) {
        int a, b;
        cin >> a >> b;
        d[a]++;
        d[b]++;
        ans = max(ans, max(d[b], d[a]));
    }
    cout << ans + 1 << endl;
    return 0;
}

