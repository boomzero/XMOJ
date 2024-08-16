#include <bits/stdc++.h>

using namespace std;

const int MAXN = 200005;
int a[MAXN] = {0}, val[MAXN << 2], lazy[MAXN << 2];

void push_up(int rt) {
    val[rt] = max(val[rt * 2], val[rt * 2 + 1]);
}

void build(int rt, int l, int r) {
    if (l == r) val[rt] = a[l];
    else {
        int mid = (l + r) / 2;
        build(rt * 2, l, mid);
        build(rt * 2 + 1, mid + 1, r);
        push_up(rt);
    }
}

void push_down(int rt, int l, int r) {
    if (lazy[rt] != 0) {
        lazy[rt * 2] += lazy[rt];
        lazy[rt * 2 + 1] += lazy[rt];
        val[rt * 2] += lazy[rt];
        val[rt * 2 + 1] += lazy[rt];
        lazy[rt] = 0;
    }
}

int query(int rt, int l, int r, int ql, int qr) {
    if (ql > r || qr < l) {
        return 0;
    }
    if (ql <= l && qr >= r)
        return val[rt];
    push_down(rt, l, r);
    int mid = (l + r) / 2;
    return max(query(rt * 2, l, mid, ql, qr), query(rt * 2 + 1, mid + 1, r, ql, qr));
}

void update(int rt, int l, int r, int ul, int ur, int add) {
    if (ul > r || ur < l) return;
    if (ul <= l && ur >= r) {
        val[rt] += add;
        lazy[rt] += add;
        return;
    }
    push_down(rt, l, r);
    int mid = (l + r) / 2;
    update(rt * 2, l, mid, ul, ur, add);
    update(rt * 2 + 1, mid + 1, r, ul, ur, add);
    push_up(rt);
}

int t, n, m;

int main() {
    freopen("score.in", "r", stdin);
   freopen("score.out", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin >> t;
    for (int o = 1; o <= t; o++) {
        memset(a, 0, sizeof(a));
        memset(lazy, 0, sizeof(lazy));
        memset(val, 0, sizeof(val));
        cin >> n >> m;
        for (int j = 1; j <= n; ++j) {
            cin >> a[j];
        }
        build(1, 1, n);
        for (int l = 1; l <= m; l++) {
            string cmd;
            cin >> cmd;
            if (cmd == "U") {
                int x, j, bj;
                cin >> x >> j;
                bj = j;
                j = j - a[x];
                a[x] = bj;
                update(1, 1, n, x, x, j);
            } else {
                int x, j;
                cin >> x >> j;
                cout << query(1, 1, n, x, j) << endl;
            }
        }
    }
    return 0;
}

