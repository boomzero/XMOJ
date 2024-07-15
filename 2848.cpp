#include <bits/stdc++.h>

typedef long long ll;
using namespace std;
bool vis[1005][1005] = {{false}};
int n;
ll height[1001][1001] = {0};
int vc = 0, hc = 0;
bool setV = false, cr = false;///set this to false after every dfs!
bool vh = false;///valley false, hill true
bool val(int r, int c) {
    return r >= 0 && r < n && c >= 0 && c < n;
}

void dfs(int r, int c) {
    vis[r][c] = true;
    for (int i = -1; i <= 1; ++i) {
        for (int j = -1; j <= 1; ++j) {
            if (i == 0 && j == 0) continue;
            if (val(r + i, c + j)) {
                if (height[r + i][c + j] > height[r][c]) {
                    if (!setV) {
                        vc++;
                        vh = false;
                        setV = true;
                    } else if (vh) {
                        if (!cr) {
                            cr = true;
                            hc--;
                        }
                    }
                } else if (height[r + i][c + j] < height[r][c]) {
                    if (!setV) {
                        hc++;
                        vh = true;
                        setV = true;
                    } else if (!vh) {
                        if (!cr) {
                            cr = true;
                            vc--;
                        }
                    }
                }
            }
            if (val(r + i, c + j) && !vis[r + i][c + j]) {
                if (height[r + i][c + j] == height[r][c]) {
                    dfs(r + i, c + j);
                }
            }
        }
    }
}

int main() {
    cin >> n;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> height[i][j];
        }
    }
    ll val = height[0][0];
    bool vah = true;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (height[i][j] != val) {
                vah = false;
                break;
            }
        }
    }
    if (vah) {
        cout << "1 1" << endl;
        return 0;
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            setV = false;
            cr = false;
            if (!vis[i][j]) {
                dfs(i, j);
            }
        }
    }
    cout << hc << " " << vc << endl;
    return 0;
}
