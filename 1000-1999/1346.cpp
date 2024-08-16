#include <bits/stdc++.h>

using namespace std;
constexpr int Max = 1000005;
int val[Max << 2], lazy[Max << 2];

void push_up(int rt) {
    val[rt] = min(val[rt * 2], val[rt * 2 + 1]);
}

void push_down(int rt) {
    if (lazy[rt]) {
        int lz = lazy[rt]; //I am lazy...
        //pass the laziness down
        lazy[rt * 2] += lz;
        lazy[rt * 2 + 1] += lz;
        val[rt * 2 + 1] += lz;
        val[rt * 2] += lz; //look! symmetrical!
        lazy[rt] = 0;
    }
}

void upd(int rt, int l, int r, int ul, int ur, int delta) { // NOLINT(*-no-recursion)
    if (r < ul || l > ur) {
        return;
    }
    if (l >= ul && r <= ur) {
        lazy[rt] += delta;
        val[rt] += delta;
        return;
    }
    push_down(rt);
    int mid = (l + r) / 2;
    upd(rt * 2, l, mid, ul, ur, delta);
    upd(rt * 2 + 1, mid + 1, r, ul, ur, delta);
    push_up(rt);
}

int query(int rt, int l, int r, int ql, int qr) { // NOLINT(*-no-recursion)
    if (r < ql || l > qr) {
        return numeric_limits<int>::max();
    }
    if (l >= ql && r <= qr) {
        return val[rt];
    }
    push_down(rt);
    int mid = (l + r) / 2;
    return min(query(rt * 2, l, mid, ql, qr), query(rt * 2 + 1, mid + 1, r, ql, qr));
}

int main() {
    int n, k, p;
    scanf("%d%d%d", &n, &k, &p); // NOLINT(*-err34-c)
    for (int i = 1; i <= k + p; ++i) {
        int op, a, b;
        scanf("%d%d%d", &op, &a, &b);  // NOLINT(*-err34-c)
        if (op == 1) {
            upd(1, 1, n, a, b, 1);
        } else {
            printf("%d\n", query(1, 1, n, a, b));
        }
    }
    return 0;
}

