#include <bits/stdc++.h>
using namespace std;
const int N = 4e5 + 10;
int tab[N << 2], len, n;
struct Square {
    int lx, ly, rx, ry;
    inline void read() {
        scanf("%d %d %d %d", &lx, &rx, &ly, &ry), ++lx, ++ly;
        tab[++len] = lx, tab[++len] = rx;
    }
    inline void print() { printf("%d %d %d %d\n", tab[lx] - 1, tab[rx], ly - 1, ry); }
    inline bool operator<(const Square &b) const { return ry < b.ry; }
    inline Square operator+(const Square &b) const { return {min(lx, b.lx), min(ly, b.ly), max(rx, b.rx), max(ry, b.ry)}; }
} a[N];
bool vis[N];
inline bool calc(int x, int y) { return !((a[x].ly > a[y].ry) || (a[y].ly > a[x].ry)); }
struct SegmentTree {
    vector<int> vec[N << 2], vec2[N << 2];
    void update(int u, int L, int R, int l, int r, int v) {
        if (L > r || R < l) return;
        vec2[u].push_back(v);
        if (L >= l && R <= r) {
            vec[u].push_back(v);
            return;
        }
        int M = L + R >> 1;
        update(u << 1, L, M, l, r, v), update(u << 1 | 1, M + 1, R, l, r, v);
    }
    bool merge(int u, int L, int R, int l, int r, int v) {
        if (L > r || R < l) return 0;
        bool flag = 0;
        for (int i = vec[u].size() - 1; ~i; i = vec[u].size() - 1) {
            if (vis[vec[u][i]]) {
                vec[u].pop_back();
                continue;
            }
            if (!calc(vec[u][i], v)) break;
            a[v] = a[v] + a[vec[u][i]], vis[vec[u][i]] = 1;
            vec[u].pop_back();
            flag = 1;
        }
        if (L >= l && R <= r) {
            for (int i = vec2[u].size() - 1; ~i; i = vec2[u].size() - 1) {
                if (vis[vec2[u][i]]) {
                    vec2[u].pop_back();
                    continue;
                }
                if (!calc(vec2[u][i], v)) break;
                a[v] = a[v] + a[vec2[u][i]], vis[vec2[u][i]] = 1;
                vec2[u].pop_back();
                flag = 1;
            }
            return flag;
        }
        int M = L + R >> 1;
        return flag | merge(u << 1, L, M, l, r, v) | merge(u << 1 | 1, M + 1, R, l, r, v);
    }
} seg;
inline bool cmp(Square a, Square b) { return a.lx != b.lx ? a.lx < b.lx : (a.rx != b.rx ? a.rx < b.rx : (a.ly != b.ly ? a.ly < b.ly : a.ry < b.ry)); }
int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) a[i].read();
    sort(a + 1, a + n + 1), sort(tab + 1, tab + len + 1), len = unique(tab + 1, tab + len + 1) - tab - 1;
    for (int i = 1; i <= n; i++) {
        a[i].lx = lower_bound(tab + 1, tab + len + 1, a[i].lx) - tab;
        a[i].rx = lower_bound(tab + 1, tab + len + 1, a[i].rx) - tab;
    }
    for (int i = 1; i <= n; i++) {
        while (seg.merge(1, 1, len, a[i].lx, a[i].rx, i))
            ;
        seg.update(1, 1, len, a[i].lx, a[i].rx, i);
    }
    // for (int i = 1; i <= n; i++) --a[i].lx, --a[i].ly;
    int cnt = 0;
    for (int i = 1; i <= n; i++)
        if (!vis[i]) a[++cnt] = a[i];
    sort(a + 1, a + cnt + 1, cmp), cout << cnt << endl;
    for (int i = 1; i <= cnt; i++) a[i].print();
    return 0;
}
