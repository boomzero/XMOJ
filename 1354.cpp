#include <bits/stdc++.h>

using namespace std;
constexpr int mx = 200005;
int a[mx << 2], val[mx << 2], lazy[mx << 2];

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

int query(int rt, int l, int r, int ql, int qr) {
    if (ql <= l && qr >= r) {
        return val[rt];
    }
    if (ql > r || qr < l) {
        return 0;
    }
    int mid = (l + r) / 2;
    push_down(rt, l, r);
    return query(rt * 2, l, mid, ql, qr) + query(rt * 2 + 1, mid + 1, r, ql, qr);
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
            int ca, x;
            scanf("%d%d", &ca, &x);
            update(1, 1, n, ca, ca, x);
        } else {
            int ca, cb;
            scanf("%d%d", &ca, &cb);
            printf("%d\n", query(1, 1, n, ca, cb));
        }
    }
    return 0;
}

