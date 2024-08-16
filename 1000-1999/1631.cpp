#include <cstdio>
#include <algorithm>
#define N 100005
using namespace std;
int n, fa[N], siz[N], ch[N][2], root, tag[N];
struct node
{
    int i, k;
} a[N];
inline bool cmp(node p, node q)
{
    if (p.k < q.k)
        return 1;
    if (p.k == q.k)
        return p.i < q.i;
    return 0;
}
inline void update(int k)
{
    siz[k] = siz[ch[k][0]] + siz[ch[k][1]] + 1;
}
inline void build(int l, int r, int f)
{
    if (l > r)
        return;
    int mid = l + r >> 1;
    if (mid < f)
        ch[f][0] = mid;
    else
        ch[f][1] = mid;
    siz[mid] = 1;
    fa[mid] = f;
    if (l == r)
        return;
    build(l, mid - 1, mid);
    build(mid + 1, r, mid);
    update(mid);
}
inline void down(int k)
{
    tag[k] ^= 1;
    if (ch[k][0])
        tag[ch[k][0]] ^= 1;
    if (ch[k][1])
        tag[ch[k][1]] ^= 1;
    swap(ch[k][0], ch[k][1]);
}
inline void rotate(int x, int &goal)
{
    int y = fa[x], z = fa[y], kind = ch[y][1] == x;
    if (y == goal)
        goal = x;
    else
        ch[z][ch[z][1] == y] = x;
    ch[y][kind] = ch[x][kind ^ 1];
    ch[x][kind ^ 1] = y;
    fa[y] = x;
    fa[x] = z;
    fa[ch[y][kind]] = y;
    update(y);
}
inline void splay(int x, int &goal)
{
    while (x != goal)
    {
        int y = fa[x], z = fa[y];
        if (tag[z])
            down(z);
        if (tag[y])
            down(y);
        if (tag[x])
            down(x);
        if (y != goal)
        {
            if (ch[y][1] == x ^ ch[z][1] == y)
                rotate(x, goal);
            else
                rotate(y, goal);
        }
        rotate(x, goal);
        update(x);
    }
}
inline int find(int now, int k)
{
    if (tag[now])
        down(now);
    int l = ch[now][0], r = ch[now][1];
    if (siz[l] + 1 == k)
        return now;
    if (k <= siz[l])
        return find(l, k);
    return find(r, k - siz[l] - 1);
}
inline void reverse(int l, int r)
{
    int x = find(root, l - 1), y = find(root, r + 1);
    splay(x, root);
    splay(y, ch[x][1]);
    tag[ch[y][0]] ^= 1;
}
int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &a[i + 1].k);
        a[i + 1].i = i + 1;
    }
    a[1].i = 1;
    a[n + 2].i = n + 2;
    a[n + 2].k = 2000000001;
    sort(a + 1, a + n + 3, cmp);
    build(1, n + 2, 0);
    root = n + 3 >> 1;
    int p;
    for (int i = 2; i <= n; i++)
    {
        splay(a[i].i, root);
        p = siz[ch[root][0]] + 1;
        printf("%d ", p - 1);
        reverse(i, p);
    }
    printf("%d", n);
}
