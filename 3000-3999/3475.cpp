#include <bits/stdc++.h>

using namespace std;

int main() {
    freopen("a.in", "r", stdin);
    freopen("a.out", "w", stdout);
    int n;
    cin >> n;
    int min = numeric_limits<int>::max(), max = numeric_limits<int>::min();
    for (int i = 0; i < n; ++i) {
        int tmp;
        cin >> tmp;
        if (tmp > max) max = tmp;
        if (tmp < min) min = tmp;
    }
    cout << max - min << endl;
    return 0;
}

