#include <bits/stdc++.h>

using namespace std;
bool rst[1005][1005], mold[1005][1005], vis[1005][1005];
vector<pair<int, int>> dotPos;

int main() {
    freopen("grain.in", "r", stdin);
    freopen("grain.out", "w", stdout);
    ios_base::sync_with_stdio(false);
    int t;
    cin >> t;
    for (int tcid = 1; tcid <= t; tcid++) {
        memset(rst, 0, sizeof(rst));
        memset(mold, 0, sizeof(mold));
        memset(vis, 0, sizeof(vis));
        dotPos.clear();
        int n, m, a, b;
        cin >> n >> m >> a >> b;
        for (int i = 1; i <= n; i++) {
            string s;
            cin >> s;
            int j = 0;
            for (char c: s) {
                j++;
                rst[i][j] = c - '0';
            }
        }
        for (int i = 1; i <= a; i++) {
            string s;
            cin >> s;
            int j = 0;
            for (char c: s) {
                j++;
                mold[i][j] = c - '0';
            }
        }
        int startX = 0, startY;
        for (int i = 1; i <= a; i++) {
            for (int j = 1; j <= b; j++) {
                if (mold[i][j]) {
                    startX = i;
                    startY = j;
                    break;
                }
            }
            if (startX != 0) break;
        }
        for (int i = 1; i <= a; i++) {
            for (int j = 1; j <= b; j++) {
                if (mold[i][j]) {
                    dotPos.emplace_back(i - startX, j - startY);
                }
            }
        }
        bool suc = true;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if (rst[i][j] && !vis[i][j]) {
                    for (auto dot: dotPos) {
                        int px = i + dot.first, py = j + dot.second;
                        if (px < 1 || px > n || py < 1 || py > m || !rst[px][py] || vis[px][py]) {
                            suc = false;
                            break;
                        }
                        vis[px][py] = true;
                    }
                    if (!suc) break;
                }
            }
            if (!suc) break;
        }
        if (suc) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
    return 0;
}

