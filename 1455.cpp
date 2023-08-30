#include <bits/stdc++.h>

using namespace std;

#define oo 0x13131313

using namespace std;

const int MAXN = 100000 * 2 + 1;

int n, id[MAXN], sz[MAXN];

int x[10000000], tot, ans;

int find(int x)

{

    if (x == id[x])
        return x;

    return id[x] = find(id[x]);
}

void uni(int a, int b)

{

    int p = find(a);

    int q = find(b);

    if (p != q)
    {

        id[p] = q;

        sz[q] += sz[p];

        if (sz[q] > ans)
            ans = sz[q];
    }
}

int idx(int v)

{

    if (x[v] == 0)
        x[v] = ++tot;

    return x[v];
}

int main()

{

    while (scanf("%d", &n) != EOF)
    {

        memset(x, 0, sizeof(x));

        tot = 0;

        ans = 1;

        for (int i = 1; i < MAXN; ++i)
            id[i] = i, sz[i] = 1;

        for (int i = 0; i < n; ++i)
        {

            int a, b;

            scanf("%d %d", &a, &b);

            a = idx(a);

            b = idx(b);

            uni(a, b);
        }

        printf("%d\n", ans);
    }

    return 0;
}
