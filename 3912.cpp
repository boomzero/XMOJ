#include <bits/stdc++.h>

using namespace std;

int main() {
    freopen("a.in", "r", stdin);
    freopen("a.out", "w", stdout);
    double n, t, a;
    cin >> n >> t >> a;
    double h[1005] = {0};
    for (int i = 1; i <= n; ++i) {
        cin >> h[i];
    }
    int minDis = numeric_limits<int>::max(), minPos;
    for (int i = 1; i <= n; ++i) {
        if (abs(a*1000 - (t*1000 - h[i] * 6)) < minDis) {
            minDis = abs(a*1000 - (t*1000 - h[i] * 6));
            minPos = i;
        }
    }
    cout << minPos << endl;
    return 0;
}
