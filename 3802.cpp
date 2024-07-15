#include <bits/stdc++.h>

using namespace std;

int a[10005] = {0}, dp[105][10005] = {0};

int main() {
    freopen("puzzle.in", "r", stdin);
    freopen("puzzle.out", "w", stdout);
    int total, t;
    cin >> total >> t;
    a[1] = 0;
    dp[1][0] = 1;
    int to = 1;
    for (int i = 1; i <= total && i * i <= total; ++i) {
        a[i + 1] = i * i;
        dp[1][i * i] = 1;
        to++;
    }
    for (int p = 2; p <= t; ++p) {
        for (int i = 1; i <= to; ++i) {
            for (int j = a[i]; j <= total; ++j) {
                dp[p][j] += dp[p - 1][j - a[i]];
            }
        }
    }
    cout << dp[t][total] << endl;
    return 0;
}

