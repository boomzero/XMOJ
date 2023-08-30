#include <bits/stdc++.h>
using namespace std;

const int mac = 5e4 + 10;

inline void in(int &read)
{
    int x = 0;
    char ch = getchar();
    while (ch < '0' || ch > '9')
        ch = getchar();
    while (ch >= '0' && ch <= '9')
        x = (x << 3) + (x << 1) + ch - '0', ch = getchar();
    read = x;
}

inline void out(int x)
{
    if (x >= 10)
    {
        out(x / 10);
    }
    putchar(x % 10 + '0');
}

int a[mac], L[mac], R[mac], id[mac], add[mac];

void update(int l, int r, int c)
{
    int p = id[l], q = id[r];
    if (p == q)
        for (int i = l; i <= r; i++)
            a[i] += c;
    else
    {
        for (int i = p + 1; i <= q - 1; i++)
            add[i] += c;
        for (int i = l; i <= R[p]; i++)
            a[i] += c;
        for (int i = L[q]; i <= r; i++)
            a[i] += c;
    }
}

int main()
{
    int n;
    in(n);
    for (int i = 1; i <= n; i++)
        in(a[i]);
    int t = sqrt(n);
    for (int i = 1; i <= t; i++)
    {
        L[i] = (i - 1) * t + 1;
        R[i] = i * t;
    }
    if (R[t] < n)
        t++, L[t] = R[t - 1] + 1, R[t] = n;
    for (int i = 1; i <= t; i++)
        for (int j = L[i]; j <= R[i]; j++)
            id[j] = i;
    for (int i = 1; i <= n; i++)
    {
        int opt, l, r, c;
        in(opt);
        in(l);
        in(r);
        in(c);
        if (!opt)
        {
            update(l, r, c);
        }
        else
        {
            out(a[r] + add[id[r]]);
            putchar('\n');
        }
    }
    return 0;
}
