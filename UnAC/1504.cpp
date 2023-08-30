#include <bits/stdc++.h>
using namespace std;
int n, v, x, c[100009], f[20009];
int main()
{
    cin >> n >> v;
    for (int i = 0; i < n; ++i)
    {
        cin >> x;
        for (int j = v; j >= x; --j)
            f[j] = max(f[j], f[j - x] + x);
    }
    cout << v - f[v];
    return 0;
}
