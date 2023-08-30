#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
#define int long long
const int maxn = 1e5 + 10;
int n, h[maxn], rkl[maxn], rkr[maxn];
namespace NodeSave
{
    struct Node
    {
        int pos, val;
        Node() {}
        Node(int x, int y)
        {
            pos = x;
            val = y;
        }
        bool operator<(const Node &A) const
        {
            return val < A.val;
        }
    } jll[maxn], jlr[maxn];
    struct T
    {
        int sum[maxn], cnt[maxn];
    } leftre, rigtre;
    int lowbit(int x)
    {
        return x & -x;
    }
}
using namespace NodeSave;
struct queryt
{
    int x, y;
    queryt()
    {
        x = 0;
        y = 0;
    }
};
namespace Erfen
{
    void modifyL(int x, int val, int num)
    { // 左边单点修改
        while (x <= n)
        {
            leftre.sum[x] += val;
            leftre.cnt[x] += num;
            x += lowbit(x);
        }
    }
    queryt queryleft(int x)
    { // 左边单点查询
        queryt ans;
        while (x)
        {
            ans.x += leftre.sum[x];
            ans.y += leftre.cnt[x];
            x -= lowbit(x);
        }
        return ans;
    }
    void modifyR(int x, int val, int num)
    { // 右边单点修改
        while (x <= n)
        {
            rigtre.sum[x] += val;
            rigtre.cnt[x] += num;
            x += lowbit(x);
        }
    }
    queryt queryjL(int l, int r)
    { // 左边区间查询
        queryt Le = queryleft(l - 1);
        queryt Ri = queryleft(r);
        queryt ans;
        ans.x = Ri.x - Le.x;
        ans.y = Ri.y - Le.y;
        return ans;
    }
    queryt queryright(int x)
    { // 右边单点查询
        queryt ans;
        while (x)
        {
            ans.x += rigtre.sum[x];
            ans.y += rigtre.cnt[x];
            x -= lowbit(x);
        }
        return ans;
    }
    queryt queryjR(int l, int r)
    { // 右边区间查询
        queryt Le = queryright(l - 1);
        queryt Ri = queryright(r);
        queryt ans;
        ans.x = Ri.x - Le.x;
        ans.y = Ri.y - Le.y;
        return ans;
    }
    int erfen(Node a[], int val)
    {
        int l = 1, r = n;
        while (l <= r)
        {
            int mid = l + r >> 1;
            if (a[mid].val <= val)
                l = mid + 1;
            else
                r = mid - 1;
        }
        return r;
    }
    int cale(int now, int gd)
    {
        int ans = abs(h[now] - gd);
        queryt hf; // 这里是花费
        int pos = erfen(jll, gd - now);
        hf = queryleft(pos);
        ans += (gd - now) * hf.y - hf.x;
        hf = queryjL(pos + 1, n);
        ans += hf.x - (gd - now) * hf.y;
        pos = erfen(jlr, gd + now);
        hf = queryright(pos);
        ans += (gd + now) * hf.y - hf.x;
        hf = queryjR(pos + 1, n);
        ans += hf.x - (now + gd) * hf.y;
        return ans;
    }
}
using namespace Erfen;
int Mx = 0x3f3f3f3f3f3f3f3f;
signed main()
{
    freopen("column.in", "r", stdin);
    freopen("column.out", "w", stdout);
    scanf("%lld", &n);
    for (int i = 1; i <= n; ++i)
    {
        scanf("%lld", &h[i]);
    }
    for (int i = 1; i <= n; ++i)
    {
        jll[i].pos = i;
        jll[i].val = h[i] - i;
        jlr[i].pos = i;
        jlr[i].val = h[i] + i;
    }
    sort(jll + 1, jll + 1 + n);
    sort(jlr + 1, jlr + 1 + n);
    for (int i = 1; i <= n; ++i)
    {
        rkr[jlr[i].pos] = i;
        rkl[jll[i].pos] = i;
    }
    for (int i = 1; i <= n; ++i)
    {
        modifyR(rkr[i], jlr[rkr[i]].val, 1);
    }
    for (int i = 1; i <= n; ++i)
    {
        modifyR(rkr[i], -jlr[rkr[i]].val, -1);
        int nl = max(i, (n - i + 1)), nr = 1e9, lmid, rmid, mid;
        while (nl + 1 < nr)
        {
            mid = nl + nr >> 1;
            lmid = mid - 1;
            rmid = mid;
            int hfl = cale(i, lmid);
            int hfr = cale(i, rmid);
            if (hfl >= hfr)
                nl = mid;
            else
                nr = mid;
        }
        Mx = min(Mx, cale(i, nl));
        Mx = min(Mx, cale(i, nr));
        modifyL(rkl[i], jll[rkl[i]].val, 1);
    }
    printf("%lld\n", Mx);
    return 0;
}
