#include <bits/stdc++.h>

using namespace std;
constexpr int mx = 100005;
int val[mx << 2];
bool lazy[mx << 2];

void push_up(int rt) {
    val[rt] = val[rt * 2] + val[rt * 2 + 1];
}

void push_down(int rt) {
    if (lazy[rt]) {
        //pass the laziness down
        lazy[rt * 2] = true;
        lazy[rt * 2 + 1] = true;
        val[rt * 2] = 0;
        val[rt * 2 + 1] = 0;
        lazy[rt] = false;
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
    push_down(rt);
    int mid = (l + r) / 2;
    return query(rt * 2, l, mid, ql, qr) + query(rt * 2 + 1, mid + 1, r, ql, qr);
}

void upd(int rt, int l, int r, int ul, int ur) {
    if (ul > r || ur < l) {
        return;
    }
    if (ul <= l && ur >= r) {
        lazy[rt] = true;
        val[rt] = 0;
        return;
    }
    push_down(rt);
    int mid = (l + r) / 2;
    upd(rt * 2, l, mid, ul, ur);
    upd(rt * 2 + 1, mid + 1, r, ul, ur);
    push_up(rt);
}

int main() {
    int l, m, q;
    scanf("%d%d%d", &l, &m, &q);
    l++;
    build(1, 1, l);
    for (int i = 1; i <= m; i++) {
        int a, b;
        scanf("%d%d", &a, &b);
        upd(1, 1, l, a + 1, b + 1);
    }
    for (int i = 1; i <= q; i++) {
        int a, b;
        scanf("%d%d", &a, &b);
        printf("%d\n", query(1, 1, l, a + 1, b + 1));
    }
    return 0;
}
