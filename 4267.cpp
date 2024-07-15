#include <bits/stdc++.h>

using namespace std;
int n, k;
int grid[105][13], mp[105][13], idt;
bool vis[105][13];
int rm[] = {1, -1, 0, 0}, cm[] = {0, 0, 1, -1};
int cnt[1024];
unordered_set<int> tbd;

//void deb() {
//    for (int i = 1; i <= n; i++) {
//        for (int j = 1; j <= 10; ++j) {
//            cout << grid[i][j];
//        }
//        cout << endl;
//    }
//    cout << endl;
//}

void dfs(int r, int c, int id) {
    auto isVal = [](int r, int c) {
        return r <= n && c <= 10 && r > 0 && c > 0;
    };
    vis[r][c] = true;
    mp[r][c] = id;
    for (int i = 0; i < 4; ++i) {
        int nr = r + rm[i], nc = c + cm[i];
        if (isVal(nr, nc) && !vis[nr][nc] && grid[nr][nc] == grid[r][c]) {
            dfs(nr, nc, id);
        }
    }
}

int main() {
    cin >> n >> k;
    for (int i = 1; i <= n; ++i) {
        string s;
        cin >> s;
        for (int j = 1; j <= 10; ++j) {
            grid[i][j] = s[j - 1] - '0';
        }
    }
    bool cg = true;
    while (cg) {
        idt = 0;
        memset(mp, 0, sizeof(mp));
        memset(cnt, 0, sizeof(cnt));
        memset(vis, false, sizeof(vis));
        cg = false;
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= 10; ++j) {
                if (!vis[i][j] && grid[i][j] != 0) {
                    dfs(i, j, ++idt);
                }
            }
        }
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= 10; ++j) {
                cnt[mp[i][j]]++;
            }
        }
        tbd.clear();
        for (int i = 1; i <= idt; i++) {
            if (cnt[i] >= k) {
                tbd.insert(i);
            }
        }
        for (int r = 1; r <= n; ++r) {
            for (int c = 1; c <= 10; ++c) {
                if (tbd.count(mp[r][c])) {
                    grid[r][c] = 0;
                    cg = true;
                    mp[r][c] = 0;
                }
            }
        }
        for (int i = n - 1; i >= 1; --i) {
            for (int j = 1; j <= 10; ++j) {
                if (grid[i + 1][j] == 0 && grid[i][j] != 0) {
                    int r = i, c = j;
                    while (grid[r + 1][c] == 0 && r < n) {
                        grid[r + 1][j] = grid[r][c];
                        //deb();
                        grid[r][c] = 0;
                        //deb();
                        r++;
                    }
                }
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= 10; ++j) {
            cout << grid[i][j];
        }
        cout << endl;
    }
    return 0;
}
