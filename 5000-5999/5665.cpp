#include <bits/stdc++.h>
#define N 5001
using namespace std;
int n, m, c, lim[N], sum[N], st[N];
long long f[N][N], dp[N];
struct node {
    int v, w;
};
vector<node> flower[N];
int main() {
    freopen("flower.in", "r", stdin);
    freopen("flower.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> n >> m >> c;
    for (int i = 1; i <= n; ++i) {
        int tmp1, tmp2, tmp3;
        cin >> tmp1 >> tmp2 >> tmp3;
        flower[tmp3].push_back((node) {tmp1, tmp2});
        sum[tmp3] += tmp2;
    }
    for (int i = 1; i <= c; ++i) {
        cin >> lim[i];
        lim[i] = min(lim[i], sum[i]);
    }
    for (int i = 1; i <= c; ++i) {
        st[i] = INT_MAX;
        for (const auto &j : flower[i]) {
            st[i] = min(st[i], j.w);
            for (int k = lim[i]; k >= j.w; --k) {
                f[i][k] = max(f[i][k], f[i][k - j.w] + j.v);
            }
        }
    }
    for (int i = 1; i <= c; ++i) {
        for (int j = m; j >= 0; --j) {
            bool flag = true;
            for (int k = st[i]; k <= lim[i]; ++k) {
                if (j < k) break;
                dp[j] = max(dp[j], dp[j - k] + f[i][k]);
                flag = false;
            }
            if (flag) break;
        }
    }
    cout << dp[m] << endl;
    return 0;
}
