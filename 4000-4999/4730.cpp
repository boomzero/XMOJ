#include <bits/stdc++.h>

#define int long long
using namespace std;
constexpr int mx = 200005;
int a[mx << 2], val[mx << 2], lazy[mx << 2];

inline int read() {
    int x = 0, f = 1;
    char ch = getchar(); // NOLINT(*-narrowing-conversions)
    while (ch < '0' || ch > '9') {
        if (ch == '-') f = -1;
        ch = getchar(); // NOLINT(*-narrowing-conversions)
    }
    while (ch >= '0' && ch <= '9') {
        x = x * 10 + ch - 48;
        ch = getchar(); // NOLINT(*-narrowing-conversions)
    }
    return x * f;
}

void push_up(int rt) {
    val[rt] = val[rt * 2] + val[rt * 2 + 1];
}

void build(int rt, int l, int r) {
    if (l == r) {
        val[rt] = a[l];
        return;
    }
    int mid = (l + r) / 2;
    build(rt * 2, l, mid);
    build(rt * 2 + 1, mid + 1, r);
    push_up(rt);
}

void push_down(int rt, int l, int r) {
    if (lazy[rt]) {
        lazy[rt * 2] += lazy[rt];
        lazy[rt * 2 + 1] += lazy[rt];
        int mid = (l + r) / 2;
        val[rt * 2] += lazy[rt] * (mid - l + 1);
        val[rt * 2 + 1] += lazy[rt] * (r - mid);
        lazy[rt] = 0;
    }
}

int query(int rt, int l, int r, int ql, int qr, int mod) {
    if (ql <= l && qr >= r) {
        return val[rt] % (mod + 1);
    }
    if (ql > r || qr < l) {
        return 0;
    }
    int mid = (l + r) / 2;
    push_down(rt, l, r);
    return (query(rt * 2, l, mid, ql, qr, mod) + query(rt * 2 + 1, mid + 1, r, ql, qr, mod)) % (mod + 1);
}


void update(int rt, int l, int r, int ul, int ur, int k) {
    if (ul <= l && ur >= r) {
        val[rt] += k * (r - l + 1);
        lazy[rt] += k;
        return;
    }
    if (ul > r || ur < l) {
        return;
    }
    push_down(rt, l, r);
    int mid = (l + r) / 2;
    update(rt * 2, l, mid, ul, ur, k);
    update(rt * 2 + 1, mid + 1, r, ul, ur, k);
    push_up(rt);
}

signed main() {
    int n;
    n = read();
    for (int i = 1; i <= n; i++) {
        a[i] = read();
    }
    build(1, 1, n);
    for (int i = 1; i <= n; i++) {
        int op, l, r, c;
        op = read();
        l = read();
        r = read();
        c = read();
        if (op == 0) {
            update(1, 1, n, l, r, c);
        } else {
            printf("%lld\n", query(1, 1, n, l, r, c) % (c + 1));
        }
    }
    return 0;
}
