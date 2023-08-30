#include <bits/stdc++.h>
int N, key, Q, ans;
int st[100009], d[100009], p[100009], size[100009], xx[100009];
int an[100009][20];
struct node_t
{
    int next;
    int node;
} s[200009];
void link(int a, int b)
{
    key++;
    s[key].next = st[b];
    s[key].node = a;
    st[b] = key;
}
void df(int pa, int nodex)
{
    d[nodex] = d[pa] + 1;
    p[nodex] = pa;
    int x = st[nodex];
    while (x)
    {
        if (s[x].node == pa)
        {
            x = s[x].next;
            continue;
        }
        df(nodex, s[x].node);
        x = s[x].next;
    }
}
void df2(int pa, int nodex)
{
    size[nodex] = xx[nodex];
    int x = st[nodex];
    while (x)
    {
        if (s[x].node == pa)
        {
            x = s[x].next;
            continue;
        }
        df2(nodex, s[x].node);
        size[nodex] += size[s[x].node];
        x = s[x].next;
    }
    if (size[nodex] == 1)
    {
        ans++;
    }
    else if (pa != 0 && size[nodex] == 0)
    {
        ans += Q;
    }
}
void cu(void)
{
    for (int i = 1; i <= N; i++)
    {
        an[i][0] = p[i];
    }
    for (int i = 1; i < 20; i++)
    {
        for (int j = 1; j <= N; j++)
        {
            an[j][i] = an[an[j][i - 1]][i - 1];
        }
    }
}
int ca(int a, int b)
{ // d[a]>=d[b]
    if (d[a] < d[b])
    {
        int tmp = a;
        a = b;
        b = tmp;
    }
    int x = d[a] - d[b];
    for (int i = 19; i >= 0; i--)
    {
        if (x >= (1 << i))
        {
            x -= (1 << i);
            a = an[a][i];
        }
    }
    for (int i = 19; i >= 0; i--)
    {
        if (an[a][i] != an[b][i])
        {
            a = an[a][i];
            b = an[b][i];
        }
    }
    if (a == b)
        return a;
    else
        return p[a];
}
int main(void)
{
    scanf("%d %d", &N, &Q);
    for (int i = 0; i < N - 1; i++)
    {
        int a, b;
        scanf("%d %d", &a, &b);
        link(a, b);
        link(b, a);
    }
    df(0, 1);
    p[1] = 1;
    cu();
    for (int i = 0; i < Q; i++)
    {
        int c, d;
        scanf("%d %d", &c, &d);
        xx[c]++;
        xx[d]++;
        xx[ca(c, d)] -= 2;
    }
    df2(0, 1);
    printf("%d\n", ans);
}
