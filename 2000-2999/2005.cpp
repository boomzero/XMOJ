#include <bits/stdc++.h>
#include <bits/extc++.h>
#define Withers using
#define AK namespace
#define IOI std;
#define ACM __gnu_pbds
Withers AK IOI;
Withers AK ACM;
#define int long long
typedef long long ll;
typedef pair<int, int> pii;
int n, m, u, v, w, x, y, z, t, l, r, minn = INT_MAX, maxx = INT_MIN, len, res, pos, id, as, k;
int a[200010];
char s[200010];
#define infll 0x3f3f3f3f3f3f3f3f
#define inf 0x3f3f3f3f
#define endl '\n'
static char buf[1000000], *paa = buf, *pddd = buf;
static char buf2[1000000], *pppp = buf2;
#define getchar() paa == pddd && (pddd = (paa = buf) + fread(buf, 1, 1000000, stdin), paa == pddd) ? EOF : *paa++
inline void pc(char ch)
{
    if (pppp - buf2 == 1000000)
        fwrite(buf2, 1, 1000000, stdout), pppp = buf2;
    *pppp++ = ch;
}
inline void pcc()
{
    fwrite(buf2, 1, pppp - buf2, stdout);
    pppp = buf2;
}
inline void read(int &n)
{
    int w = 1;
    register int x(0);
    register char c(getchar());
    while (c < '0' || c > '9')
    {
        if (c == '-')
            w = -1;
        c = getchar();
    }
    while (c >= '0' && c <= '9')
        x = (x << 1) + (x << 3) + (c ^ 48), c = getchar();
    n = w * x;
    return;
}
inline void write(int x)
{
    if (x < 0)
        pc('-'), x = -x;
    static int sta[20];
    int top = 0;
    do
    {
        sta[top++] = x % 10, x /= 10;
    } while (x);
    while (top)
        pc(sta[--top] + 48);
}
inline void we(int x)
{
    write(x);
    pc('\n');
}
inline void ws(int x)
{
    write(x);
    pc(' ');
}
#define rd read
#define Y cout << "YES" << endl
#define N cout << "NO" << endl
#define deb(x) cout << #x << "=" << x << " ";
vector<pii> g[100010];
set<pii> st;
int d[100010];
int dis[100010];
int f[100010][30], lg[100010];
int dfn[100010];
int cnt = 0, ans = 0;
void dfs(int u, int fa)
{
    f[u][0] = fa;
    d[u] = d[fa] + 1;
    dfn[u] = ++cnt;
    for (int i = 1; i <= lg[d[u]]; i++)
    {
        f[u][i] = f[f[u][i - 1]][i - 1];
    }
    for (auto i : g[u])
    {
        if (i.first != fa)
        {
            dis[i.first] = dis[u] + i.second;
            dfs(i.first, u);
        }
    }
}
int lca(int u, int v)
{
    if (d[u] < d[v])
        swap(u, v);
    while (d[u] > d[v])
    {
        u = f[u][lg[d[u] - d[v]] - 1];
    }
    if (u == v)
        return u;
    for (int k = lg[d[u] - 1]; k >= 0; --k)
    {
        if (f[u][k] != f[v][k])
            u = f[u][k], v = f[v][k];
    }
    return f[u][0];
}
int dl(int x, int y) { return dis[x] + dis[y] - 2 * dis[lca(x, y)]; }
int get(int x)
{
    int l, r;
    auto it = st.lower_bound({dfn[x], x});
    if (it == st.end())
        r = st.begin()->second;
    else
        r = it->second;
    if (it == st.begin())
        l = st.rbegin()->second;
    else
        l = (--it)->second;
    return dl(l, x) + dl(r, x) - dl(l, r);
}
int q;
signed main()
{
    rd(n); // rd(q);//rd(m);
    for (int i = 1; i <= n; i++)
        lg[i] = lg[i - 1] + (1 << lg[i - 1] == i);
    for (int i = 1; i < n; i++)
    {
        rd(x);
        rd(y);
        rd(z);
        g[x].push_back({y, z});
        g[y].push_back({x, z});
    }
    // Y;
    dfs(1, 1);
    // cout<<dis[1]<<" "<<dis[2]<<" "<<dis[3]<<" "<<dis[4]<<endl;
    rd(q);
    char op = '=';
    // Y;
    while (q--)
    {
        op = getchar();
        while (!(op == '+' || op == '-' || op == '?'))
            op = getchar();
        if (op == '+')
        {
            rd(x);
            if (!st.empty())
                ans += get(x);
            st.insert({dfn[x], x});
        }
        else if (op == '-')
        {
            rd(x);
            auto it = st.lower_bound({dfn[x], x});
            st.erase(it);
            if (!st.empty())
                ans -= get(x);
        }
        else
            we(ans / 2);
    }
    pcc();
}
