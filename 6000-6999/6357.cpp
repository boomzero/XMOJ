#include <bits/stdc++.h>

#define MAXN 500100
#define MAXM 1000100

using namespace std;

typedef long long ll;

const int MOD = 1e9 + 7;

int n, m, p;
int tot, tot2, head[MAXN], head2[MAXN];
int cnt, top, stk[MAXN], dfn[MAXN], low[MAXN], bel[MAXN];
int deg[MAXN], V[MAXN], E[MAXN], s[MAXN];
bool ins[MAXN];
ll ans, f[MAXN][2];

struct Edge {
    int to, nxt;
} e[MAXM << 1], e2[MAXM << 1];

template<typename _T>
void read(_T &_x) {
    _x = 0;
    _T _f = 1;
    char _ch = getchar();
    while (_ch < '0' || '9' < _ch) {
        if (_ch == '-') _f = -1;
        _ch = getchar();
    }
    while ('0' <= _ch && _ch <= '9') {
        _x = (_x << 3) + (_x << 1) + (_ch & 15);
        _ch = getchar();
    }
    _x *= _f;
}

template<typename _T>
void write(_T _x) {
    if (_x < 0) {
        putchar('-');
        _x = -_x;
    }
    if (_x > 9) write(_x / 10);
    putchar('0' + _x % 10);
}

void add(int u, int v) {
    e[++tot] = Edge{v, head[u]};
    head[u] = tot;
}

void add2(int u, int v) {
    e2[++tot2] = Edge{v, head2[u]};
    head2[u] = tot2;
}

void tarjan(int u, int fa) {
    dfn[u] = low[u] = ++cnt;
    ins[u] = 1, stk[++top] = u;
    for (int i = head[u], v; i; i = e[i].nxt) {
        v = e[i].to;
        if (v == fa) continue;
        if (!dfn[v]) {
            tarjan(v, u);
            low[u] = min(low[u], low[v]);
        } else if (ins[v]) low[u] = min(low[u], dfn[v]);
    }
    if (dfn[u] == low[u]) {
        p++;
        int x;
        do {
            // 因为不需要知道每个边双连通分量里都有哪些点，只记录每个点属于哪个边双连通分量即可。
            x = stk[top--];
            ins[x] = 0;
            bel[x] = p;
            V[p]++; // 累加该边双连通分量内点数
        } while (x != u);
    }
}

ll qp(ll base, int e) { // 快速幂
    ll res = 1;
    while (e) {
        if (e & 1) res = res * base % MOD;
        base = base * base % MOD;
        e >>= 1;
    }
    return res;
}

void dfs(int u, int fa) { // dfs 计算 s[]
    s[u] = E[u];
    for (int i = head2[u], v; i; i = e2[i].nxt) {
        v = e2[i].to;
        if (v == fa) continue;
        dfs(v, u);
        s[u] += s[v] + 1;
    }
}


void dp(int u, int fa) { // 树形 DP
    for (int i = head2[u], v; i; i = e2[i].nxt) {
        v = e2[i].to;
        if (v == fa) continue;
        dp(v, u);
        // 状态转移
        f[u][1] = (f[u][1] * (((f[v][0] << 1) + f[v][1]) % MOD) % MOD + f[u][0] * f[v][1] % MOD) % MOD;
        f[u][0] = f[u][0] * ((f[v][0] << 1) % MOD) % MOD;
    }
    // 统计答案
    if (u == 1) ans = (ans + f[u][1]) % MOD; // 特判 1 号结点的特殊情况
    else ans = (ans + f[u][1] * qp(2, s[1] - s[u] - 1)) % MOD;
}

int main() {
    freopen("barrack.in","r",stdin);
    freopen("barrack.out","w",stdout);
    read(n), read(m);
    while (m--) {
        int u, v;
        read(u), read(v);
        add(u, v), add(v, u);
    }
    tarjan(1, 0); // 边双缩点
    for (int u = 1; u <= n; u++) {
        for (int i = head[u], v; i; i = e[i].nxt) {
            v = e[i].to;
            if (bel[u] != bel[v]) add2(bel[u], bel[v]); // 如果属于两个不同的边双连通分量，则将这两个边双连通分量连边
            else E[bel[u]]++; // 否则该双连通分量内边数 + 1
        }
    }
    for (int i = 1; i <= p; i++) {
        E[i] >>= 1; // 因为是无向边，每一条边会累加 2 次，故 E[i] 需要除以 2
        // 赋初值
        f[i][0] = qp(2, E[i]);
        f[i][1] = qp(2, V[i] + E[i]) - f[i][0];
    }
    dfs(1, 0);
    dp(1, 0);
    write(ans);
    return 0;
}
