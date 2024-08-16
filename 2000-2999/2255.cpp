#include <bits/stdc++.h>

using namespace std;
int dp[400000] = {0}, w[50000] = {0}, c[50000] = {0}, subC[50000][10] = {{0}}, subW[50000][10] = {{0}};
bool hasSub[20000][10] = {{false}};

int main() {
     freopen("budget.in","r",stdin);freopen("budget.out","w",stdout);
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= m; ++i) {
        int v, p, q;
        cin >> v >> p >> q; ///price imp sub
        if (q == 0) {
            c[i] = v;
            w[i] = v * p;
        } else {
            if (!hasSub[q][1]) {
                hasSub[q][1] = true;
                subC[q][1] = v;
                subW[q][1] = v * p;
            } else {
                subW[q][0]++;
                hasSub[q][2] = true;
                subC[q][2] = v;
                subW[q][2] = v * p;
            }
        }
    }
    for (int i = 1; i <= m; ++i) {
        if (w[i] == 0) continue;
        for (int j = n; j >= c[i]; --j) {
            dp[j] = max(dp[j], dp[j - c[i]] + w[i]);
            if (hasSub[i][1] && j >= c[i] + subC[i][1]) {
                dp[j] = max(dp[j], dp[j - c[i] - subC[i][1]] + w[i] + subW[i][1]);
            }
            if (hasSub[i][2] && j >= c[i] + subC[i][2]) {
                dp[j] = max(dp[j], dp[j - c[i] - subC[i][2]] + w[i] + subW[i][2]);
            }
            if (hasSub[i][1] && hasSub[i][2] && j >= c[i] + subC[i][2] + subC[i][1]) {
                dp[j] = max(dp[j], dp[j - c[i] - subC[i][1] - subC[i][2]] + w[i] + subW[i][1] + subW[i][2]);
            }
        }
    }
    cout << dp[n] << endl;
    return 0;
}
