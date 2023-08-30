#include <bits/stdc++.h>
using namespace std;
int n, p[2001] = {0}, f[2001] = {0};
int cut(int l)
{
    if (l == 0)
        return 0;
    if (f[l] > 0)
        return f[l];
    for (int i = 1; i <= l; ++i)
    {
        f[l] = max(f[l], cut(l - i) + p[i]);
    }
    return f[l];
}
int main()
{
    fill_n(p, 2000, -1);
    cin >> n;
    for (int i = 1; i <= n; ++i)
    {
        cin >> p[i];
    }
    int k;
    cin >> k;
    for (int i = 0; i < k; ++i)
    {
        int t;
        cin >> t;
        cout << cut(t) << endl;
    }
    return 0;
}
