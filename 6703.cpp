#include <bits/stdc++.h>

using namespace std;

int main() {
    freopen("swap.in", "r", stdin);
    freopen("swap.out", "w", stdout);
    int ball[4] = {0}, n, m;
    cin >> n >> m;
    ball[n] = 1;
    for (int i = 0; i < m; ++i) {
        int p, q;
        cin >> p >> q;
        swap(ball[p], ball[q]);
    }
    for (int i = 1; i <= 3; ++i) {
        if (ball[i] == 1) {
            cout << i << endl;
            break;
        }
    }
    return 0;
}
