#include <bits/stdc++.h>
using namespace std;
const int MAXN = 510;
int p, a[MAXN], b[MAXN], c[MAXN], la, lb, lc;
void mul(int a[], int &la, int b[], int lb)
{
    memset(c, 0, sizeof(c));
    lc = min(la + lb - 1, 500);
    for (int i = 0; i < la; ++i)
        for (int j = 0; j < lb; ++j)
            if (i + j < 500)
                c[i + j] += a[i] * b[j];
    for (int i = 0; i < lc; ++i)
    {
        c[i + 1] += c[i] / 10;
        c[i] %= 10;
    }
    while (c[lc] && lc < 500)
    {
        c[lc + 1] += c[lc] / 10;
        c[lc++] %= 10;
    }
    if (lc > 500)
        lc = 500, c[500] = 0;
    la = lc;
    memcpy(a, c, sizeof(int) * 500);
}
void ksm(int p)
{
    a[0] = 1, la = 1, b[0] = 2, lb = 1;
    while (p)
    {
        if (p & 1)
            mul(a, la, b, lb);
        mul(b, lb, b, lb);
        p >>= 1;
    }
}
int main()
{
    cin >> p;
    ksm(p);
    --a[0];
    cout << (int)(log10(2) * p + 1) << endl;
    for (int i = 499; i >= 0; --i)
    {
        cout << a[i];
        if (i % 50 == 0)
            cout << endl;
    }
    return 0;
}
