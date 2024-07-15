#include <bits/stdc++.h>

using namespace std;
int a[501][501] = {{0}};
int ft[501][501] = {{0}};

int f(int i, int j) {
    if (i == 1 && j == 1) {
        ft[i][j] = a[1][1];
        return a[1][1];
    }
    if (j == 1) {
        if (ft[i][j] != -1) {
            return ft[i][j];
        }
        ft[i][j] = f(i - 1, 1) + a[i][1];
        return ft[i][j];
    }
    if (i == j) {
        if (ft[i][j] != -1) {
            return ft[i][j];
        }
        ft[i][j] = f(i - 1, j - 1) + a[i][i];
        return ft[i][j];
    }
    if (ft[i][j] != -1) {
        return ft[i][j];
    }
    ft[i][j] = max(f(i - 1, j - 1), f(i - 1, j)) + a[i][j];
    return ft[i][j];
}

int main() {
    int n;
    cin >> n;
    memset(ft,-1,sizeof(ft));
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= i; ++j) {
            cin >> a[i][j];
        }
    }
    int max = -1;
    for (int i = 1; i <= n; ++i) {
        int tmp = f(n, i);
        if (tmp > max) {
            max = tmp;
        }
    }
    cout << max << endl;
    return 0;
}


