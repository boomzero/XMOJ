#include <bits/stdc++.h>

using namespace std;
int n, arr[6][20005] = {{0}}, can = 0, st[20005] = {0}, pos[6][20005] = {0};
map<int, int> lu, rlu;

int allocNum(int f) {
    if (!lu.count(f)) {
        can++;
        lu[f] = can;
        rlu[can] = f;
        return can;
    } else {
        return lu[f];
    }
}

bool cmp(int a, int b) {
    int av = 0, bv = 0;
    for (int i = 1; i <= 5; ++i) {
        if (pos[i][a] < pos[i][b]) av++;
        else av--;
    }
    return av > bv;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin >> n;
    for (int i = 1; i <= 5; ++i) {
        for (int j = 1; j <= n; ++j) {
            cin >> arr[i][j];
            arr[i][j] = allocNum(arr[i][j]);
            pos[i][arr[i][j]] = j;
        }
    }
    for (int i = 1; i <= n; i++) {
        st[i] = arr[1][i];
    }
    sort(st + 1, st + 1 + n, cmp);
    for (int i = 1; i <= n; i++) {
        cout << rlu[st[i]] << endl;
    }
    return 0;
}

