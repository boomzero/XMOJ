#include <bits/stdc++.h>

using namespace std;
constexpr int mx = 200005;
int a[mx << 2], val[mx << 2], lazy[mx << 2];

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

int main() {
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) {
        scanf("%d", &a[i]);
    }
    build(1, 1, n);
    int q;
    scanf("%d", &q);
    for (int i = 1; i <= q; ++i) {
        int op;
        scanf("%d", &op);
        if (op == 1) {
            int ca, cb, x;
            scanf("%d%d%d", &ca, &cb, &x);
            update(1, 1, n, ca, cb, x);
        } else {
            int q;
            scanf("%d", &q);
            printf("%d\n", query(1, 1, n, q, q));
        }
    }
    return 0;
}

