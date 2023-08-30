#include <bits/stdc++.h>
using namespace std;
constexpr int MAX_N = 1000005;
int b[MAX_N] = {0}, a[MAX_N] = {0}, n, len = 1, f[MAX_N] = {0}, rpv[MAX_N];
int main()
{
    cin >> n;
    for (int i = 1; i <= n; ++i)
    {
        cin >> a[i];
        rpv[a[i]] = i;
    }
    for (int i = 1; i <= n; ++i)
    {
        cin >> b[i];
    }
    for (int i = 1; i <= n; ++i)
    {
        b[i] = rpv[b[i]];
    }
    f[1] = b[1];
    for (int i = 2; i <= n; ++i)
    {
        int j = upper_bound(f + 1, f + 1 + len, b[i]) - f;
        f[j] = b[i];
        len = max(len, j);
    }
    cout << len << endl;
    return 0;
}
