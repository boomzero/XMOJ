#include <bits/stdc++.h>
using namespace std;
const int N = 110;
int n, v[N], lc[N], rs[N], root;
bool direct_do(int x, int y)
{
    if (x == y)
        return true;
    int c = lc[x];
    while (c)
    {
        if (direct_do(c, y))
            return true;
        c = rs[c];
    }
    return false;
}
int direct(int x, int y)
{
    if (direct_do(x, y))
        return x;
    if (direct_do(y, x))
        return y;
    return -1;
}
int main()
{
    cin >> n >> root;
    for (int i = 1; i <= n; ++i)
        cin >> v[i] >> lc[i] >> rs[i];
    int k, x, y;
    cin >> k;
    while (k--)
    {
        cin >> x >> y;
        cout << direct(x, y) << endl;
    }
    return 0;
}
