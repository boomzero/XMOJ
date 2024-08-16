#include <bits/stdc++.h>

using namespace std;

const int MAXN = 200005;
int a[MAXN] = {0}, val[MAXN << 2], lazy[MAXN << 2];

void push_up(int rt) {
    val[rt] = val[rt * 2] + val[rt * 2 + 1];
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
        val[rt * 2] += ((l + r) / 2 - l + 1) * lazy[rt];
        val[rt * 2 + 1] += (r - (l + r) / 2) * lazy[rt];
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
    return query(rt * 2, l, mid, ql, qr) + query(rt * 2 + 1, mid + 1, r, ql, qr);
}

void update(int rt, int l, int r, int ul, int ur, int add) {
    if (ul > r || ur < l) return;
    if (ul <= l && ur >= r) {
        val[rt] += add * (r - l + 1);
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
    for (int i = 1; i <= n; ++i) {
        int op;
        scanf("%d", &op);
        if (op == 0) {
            int ca, cb, x;
            scanf("%d%d%d", &ca, &cb, &x);
            update(1, 1, n, ca, cb, x);
        } else {
            int x, b;
            scanf("%d%d%d", &b, &x, &b);
            printf("%d\n", query(1, 1, n, x, x));
        }
    }
    return 0;
}
