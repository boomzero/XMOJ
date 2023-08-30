#include <bits/stdc++.h>

#define debug print(root), printf("\n")

using namespace std;

const int N = 500010;

const int inf = 0x3f3f3f3f;

queue<int> q;

namespace IO
{

    int read()
    {

        int ans = 0, f = 1;
        char i = getchar();

        while (i < '0' || i > '9')
        {
            if (i == '-')
                f = -1;
            i = getchar();
        }

        while (i >= '0' && i <= '9')
        {
            ans = ans * 10 + i - '0';
            i = getchar();
        }

        return ans * f;
    }

}

using namespace IO;

namespace Splay
{

    int n, m, root, cnt = 0, a[N], id[N];

    char opt[10];

    struct splay
    {

        int ch[2], fa, size, mx, lx, rx, sum, upd, rev, val;

    } t[N];

    void print(int x)
    {

        if (t[x].ch[0])

            print(t[x].ch[0]);

        if (t[x].val != -inf)

            printf("%d", t[x].val);

        if (t[x].ch[1])

            print(t[x].ch[1]);
    }

    bool get(int x)
    {

        return x == t[t[x].fa].ch[1];
    }

    void pushup(int x)
    {

        int l = t[x].ch[0], r = t[x].ch[1];

        t[x].size = t[l].size + t[r].size + 1;

        t[x].sum = t[l].sum + t[r].sum + t[x].val;

        t[x].lx = max(t[l].lx, t[l].sum + t[x].val + t[r].lx);

        t[x].rx = max(t[r].rx, t[r].sum + t[x].val + t[l].rx);

        t[x].mx = max(max(t[l].mx, t[r].mx), t[l].rx + t[x].val + t[r].lx);
    }

    void pushdown(int x)
    {

        int l = t[x].ch[0], r = t[x].ch[1];

        if (t[x].upd)
        {

            int v = t[x].val;

            t[x].upd = t[x].rev = 0;

            if (l)

                t[l].val = v, t[l].upd = 1, t[l].sum = t[l].size * v;

            if (r)

                t[r].val = v, t[r].upd = 1, t[r].sum = t[r].size * v;

            if (v >= 0)
            {

                if (l)

                    t[l].lx = t[l].rx = t[l].mx = t[l].sum;

                if (r)

                    t[r].lx = t[r].rx = t[r].mx = t[r].sum;
            }

            else
            {

                if (l)

                    t[l].lx = t[l].rx = 0, t[l].mx = v;

                if (r)

                    t[r].lx = t[r].rx = 0, t[r].mx = v;
            }
        }

        if (t[x].rev)
        {

            t[l].rev ^= 1, t[r].rev ^= 1;

            t[x].rev = 0;

            swap(t[l].lx, t[l].rx);

            swap(t[r].lx, t[r].rx);

            swap(t[l].ch[1], t[l].ch[0]);

            swap(t[r].ch[1], t[r].ch[0]);
        }
    }

    void rotate(int x)
    {

        int fa = t[x].fa, gfa = t[fa].fa, d1 = get(x), d2 = get(fa);

        t[t[x].ch[d1 ^ 1]].fa = fa;

        t[fa].ch[d1] = t[x].ch[d1 ^ 1];

        t[fa].fa = x;

        t[x].ch[d1 ^ 1] = fa;

        t[x].fa = gfa;

        t[gfa].ch[d2] = x;

        pushup(fa), pushup(x);
    }

    void splay(int x, int goal)
    {

        while (t[x].fa != goal)
        {

            int fa = t[x].fa, gfa = t[fa].fa, d1 = get(x), d2 = get(fa);

            if (goal != gfa)
            {

                if (d1 == d2)

                    rotate(fa);

                else

                    rotate(x);
            }

            rotate(x);
        }

        if (goal == 0)

            root = x;
    }

    int kth(int node, int k)
    {

        pushdown(node);

        int l = t[node].ch[0], r = t[node].ch[1];

        if (k <= t[l].size)

            return kth(l, k);

        else if (k == t[l].size + 1)

            return node;

        else

            return kth(r, k - t[l].size - 1);
    }

    void build(int l, int r, int f)
    {

        int mid = (l + r >> 1), node = id[mid], fa = id[f];

        // printf("a[%d]=%d\n",mid,a[mid]);

        if (l == r)
        {

            t[node].mx = t[node].sum = a[l];

            t[node].lx = t[node].rx = max(a[l], 0);

            t[node].size = 1;

            t[node].rev = t[node].upd = 0;
        }

        if (l < mid)

            build(l, mid - 1, mid);

        if (mid < r)

            build(mid + 1, r, mid);

        t[node].val = a[mid], t[node].fa = fa;

        pushup(node);

        t[fa].ch[f <= mid] = node;
    }

    void insert(int k, int tot)
    {

        for (int i = 1; i <= tot; i++)

            a[i] = read();

        for (int i = 1; i <= tot; i++)

            if (!q.empty())

                id[i] = q.front(), q.pop();

            else

                id[i] = ++cnt;

        build(1, tot, 0);

        int rt = id[1 + tot >> 1], pre = kth(root, k + 1), nex = kth(root, k + 2);

        splay(pre, 0);

        splay(nex, pre);

        t[nex].ch[0] = rt;

        t[rt].fa = nex;

        pushup(nex), pushup(pre);
    }

    void reuse(int node)
    {

        if (t[node].ch[0])

            reuse(t[node].ch[0]);

        if (t[node].ch[1])

            reuse(t[node].ch[1]);

        q.push(node);

        t[node].ch[0] = t[node].ch[1] = 0;

        t[node].fa = t[node].rev = t[node].upd = 0;
    }

    int split(int k, int tot)
    {

        int pre = kth(root, k);

        int nex = kth(root, k + tot + 1);

        splay(pre, 0);

        splay(nex, pre);

        // printf("pre=%dnex=%d\n",pre,nex);

        return t[nex].ch[0];
    }

    void reverse(int k, int tot)
    {

        int rt = split(k, tot);

        int fa = t[rt].fa;

        if (t[rt].upd == 0)
        {

            t[rt].rev ^= 1;

            swap(t[rt].ch[0], t[rt].ch[1]);

            swap(t[rt].lx, t[rt].rx);

            pushup(fa), pushup(t[fa].fa);
        }
    }

    void del(int k, int tot)
    {

        int rt = split(k, tot), fa = t[rt].fa;

        reuse(rt);

        t[fa].ch[0] = 0;

        pushup(fa);

        pushup(t[fa].fa);
    }

    void update(int k, int tot, int c)
    {

        int rt = split(k, tot), fa = t[rt].fa;

        t[rt].val = c, t[rt].upd = 1, t[rt].sum = c * t[rt].size;

        if (c >= 0)

            t[rt].lx = t[rt].rx = t[rt].mx = t[rt].sum;

        else

            t[rt].lx = t[rt].rx = 0, t[rt].mx = c;

        pushup(fa);

        pushup(t[fa].fa);
    }

    int get_sum(int k, int tot)
    {

        int rt = split(k, tot);

        return t[rt].sum;
    }

    int max_sum()
    {

        return t[root].mx;
    }

}

using namespace Splay;

int main()
{

    int x, y, z;

    n = read();

    m = read();

    a[1] = -inf;

    a[n + 2] = -inf;

    t[0].mx = -inf;

    for (int i = 2; i <= n + 1; i++)

        a[i] = read();

    for (int i = 1; i <= n + 2; i++)

        id[i] = i;

    build(1, n + 2, 0);

    root = (n + 3 >> 1);

    cnt = n + 2;

    for (int i = 1; i <= m; i++)
    {

        scanf("%s", opt);

        if (opt[2] == 'S')

            x = read(), y = read(), insert(x, y);

        if (opt[2] == 'L')

            x = read(), y = read(), del(x, y);

        if (opt[2] == 'K')

            x = read(), y = read(), z = read(), update(x, y, z);

        if (opt[2] == 'V')

            x = read(), y = read(), reverse(x, y);

        if (opt[2] == 'T')

            x = read(), y = read(), printf("%d\n", get_sum(x, y));

        if (opt[2] == 'X')

            printf("%d\n", max_sum());
    }

    return 0;
}
