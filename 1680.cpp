#include <bits/stdc++.h>

using namespace std;
int n, grid[35][35] = {{0}}, xc[] = {0, 0, -1, 1}, yc[] = {0, 0, -1, 1};

void dfs(int ti, int tj) {
    grid[ti][tj] = 0;
    for (int i: xc) {
        for (int j: yc) {
            if (grid[ti + i][tj + j] == 2) {
                dfs(ti + i, tj + j);
            }
        }
    }
}

int main() {
    cin >> n;
    memset(grid, -1, sizeof(grid));
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            cin >> grid[i][j];
            if (grid[i][j] == 0) grid[i][j] = 2;
        }
    }
    for (int i = 1; i <= n; ++i) {
        if (grid[i][0] != 1) {
            dfs(i, 0);
        }
        if (grid[0][i] != 1) {
            dfs(0, i);
        }
        if (grid[n][i] != 1) {
            dfs(n, i);
        }
        if (grid[i][n] != 1) {
            dfs(i, n);
        }
    }
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            cout << grid[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}

