#include <bits/stdc++.h>

using namespace std;
int dp[2005] = {0}, h[2500] = {0}, n;

int main() {
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> h[i];
    }
    for (int i = 1; i <= n; ++i) {
        int max = -1;
        for (int j = 1; j <= i; ++j) {
            if (dp[j] > max && h[j] >= h[i]) max = dp[j];
        }
        dp[i] = max + 1;
    }
    int max = -1;
    for (int i = 1; i <= n; ++i) {
        if (dp[i] > max) max = dp[i];
    }
    cout << max << endl;
    return 0;
}

