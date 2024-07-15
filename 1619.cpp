#include <bits/stdc++.h>

using namespace std;
const int N = 100005;
int rt, tot;
int fa[N], ch[N][2], val[N], cnt[N], sz[N];

void clear(int x) {
    fa[x] = ch[x][0] = ch[x][1] = val[x] = cnt[x] = sz[x] = 0;
}

bool get(int x) {
    return ch[fa[x]][1] == x;
}

void push_up(int x) {
    if (x) {
        sz[x] = cnt[x];
        if (ch[x][1]) {
            sz[x] += sz[ch[x][1]];
        }
        if (ch[x][0]) {
            sz[x] += sz[ch[x][0]];
        }
    }
}

void rotate(int x) {
    int y = fa[x], z = fa[y], k = get(x);
    ch[y][k] = ch[x][k ^ 1];
    fa[ch[x][k ^ 1]] = y;
    ch[x][k ^ 1] = y;
    fa[y] = x;
    fa[x] = z;
    if (z) ch[z][ch[z][1] == y] = x;
    push_up(y);
    push_up(x);
}

void splay(int x, int goal = 0) {
    while (fa[x] != goal) {
        int y = fa[x], z = fa[y];
        if (z != goal) rotate(get(x) == get(y) ? y : x);
        rotate(x);
    }
    if (goal == 0) rt = x;
}

void find(int x) {
    int c = rt;
    while (ch[c][x > val[c]] && val[c] != x) {
        c = ch[c][x > val[c]];
    }
    splay(c);
}

void ins(int x) {
    int c = rt, f = 0;
    while (c && val[c] != x) {
        f = c;
        c = ch[c][x > val[c]];
    }
    if (c) {
        cnt[c]++;
        push_up(c);
        push_up(f);
    } else {
        c = ++tot;
        clear(c);
        fa[c] = f;
        cnt[c] = sz[c] = 1;
        val[c] = x;
        if (f) {
            ch[f][x > val[f]] = c;
            push_up(f);
        } else rt = c;
    }
    splay(c);
}

int query_rank(int x) {
    find(x);
    return sz[ch[rt][0]] + 1;
}

int query_kth(int k) {
    int c = rt;
    while (true) {
        if (ch[c][0] && k <= sz[ch[c][0]]) {
            c = ch[c][0];
        } else {
            int tmp = sz[ch[c][0]] + cnt[c];
            if (k <= tmp) {
                return val[c];
            }
            k -= tmp;
            c = ch[c][1];
        }
    }
}

int pre(int x) {
    find(x);
    if (val[rt] < x) return rt;
    int c = ch[rt][0];
    while (ch[c][1]) c = ch[c][1];
    return c;
}

int nxt(int x) {
    find(x);
    if (val[rt] > x)
        return rt;
    int c = ch[rt][1];
    while (ch[c][0]) c = ch[c][0];
    return c;
}

void del(int x) {
    find(x);
    if (val[rt] != x) return;
    if (cnt[rt] > 1) {
        cnt[rt]--;
        push_up(rt);
        return;
    }
    if (!ch[rt][0] && !ch[rt][1]) {
        clear(rt);
        rt = 0;
        return;
    }
    if (!ch[rt][0] || !ch[rt][1]) {
        rt = ch[rt][0] + ch[rt][1];
        fa[rt] = 0;
        return;
    }
    int prevRt = rt, leftBig = pre(x);
    splay(leftBig);
    ch[rt][1] = ch[prevRt][1];
    fa[ch[prevRt][1]] = rt;
    push_up(rt);
    clear(prevRt);
}

int insq[N], instl;

signed main() {
    int n, vc;
    cin >> vc >> n;
    ins(0);
    ins(vc + 1);
    for (int i = 1; i <= n; ++i) {
        int x;
        char op = getchar();
        while (op == ' ' || op == '\n') op = getchar();
        //scanf("%d", &op);
        if (op == 'D') {
            scanf("%d", &x);
            insq[++instl] = x;
            ins(x);
        } else if (op == 'Q') {
            scanf("%d", &x);
            find(x);
            if (val[rt] == x) {
                cout << 0 << endl;
                continue;
            }
            cout << val[nxt(x)] - val[pre(x)] - 1 << endl;
        } else {
            del(insq[instl]);
            instl--;
        }
    }
    return 0;
}
