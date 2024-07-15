#include <bits/stdc++.h>

using namespace std;
constexpr int mx = 100005;
int val[mx << 2];
int lazy[mx << 2];

void push_up(int rt) {
    val[rt] = val[rt * 2] + val[rt * 2 + 1];
}

void push_down(int rt, int l, int r) {
    if (lazy[rt] == 0) {
        //pass the laziness down
        lazy[rt * 2] = 0;
        lazy[rt * 2 + 1] = 0;
        val[rt * 2] = 0;
        val[rt * 2 + 1] = 0;
        lazy[rt] = -1;
    } else if (lazy[rt] == 1) {
        //pass the laziness down
        lazy[rt * 2] = 1;
        lazy[rt * 2 + 1] = 1;
        int mid = (l + r) / 2;
        val[rt * 2] = mid - l + 1;
        val[rt * 2 + 1] = r - mid;
        lazy[rt] = -1;
    }
}

void build(int rt, int l, int r) {
    if (l == r) {
        val[rt] = 1;
        return;
    }
    int mid = (l + r) / 2;
    build(rt * 2, l, mid);
    build(rt * 2 + 1, mid + 1, r);
    push_up(rt);
}

int query(int rt, int l, int r, int ql, int qr) {
    if (ql > r || qr < l) {
        return 0;
    }
    if (ql <= l && qr >= r) {
        return val[rt];
    }
    push_down(rt, l, r);
    int mid = (l + r) / 2;
    return query(rt * 2, l, mid, ql, qr) + query(rt * 2 + 1, mid + 1, r, ql, qr);
}

void upd(int rt, int l, int r, int ul, int ur, int cl) {
    if (ul > r || ur < l) {
        return;
    }
    if (ul <= l && ur >= r) {
        if (cl == 0) {
            lazy[rt] = 0;
            val[rt] = 0;
        } else {
            lazy[rt] = 1;
            val[rt] = (r - l) + 1;
        }
        return;
    }
    push_down(rt, l, r);
    int mid = (l + r) / 2;
    upd(rt * 2, l, mid, ul, ur, cl);
    upd(rt * 2 + 1, mid + 1, r, ul, ur, cl);
    push_up(rt);
}

int main() {
    int l, q;
    memset(lazy, -1, sizeof(lazy));
    scanf("%d%d", &l, &q);
    build(1, 1, l);
    for (int i = 1; i <= q; i++) {
        int a, b, c;
        scanf("%d%d%d", &a, &b, &c);
        upd(1, 1, l, a, b, (c == 1 ? 1 : 0));
    }
    printf("%d\n", query(1, 1, l, 1, l));
    return 0;
}
