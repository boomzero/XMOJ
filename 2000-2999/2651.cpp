#include <bits/stdc++.h>
using namespace std;
int a[1010], x, y, n, ans;
int main()
{
    cin >> n;
    for (int i = 1; i < n; i++)
    {
        cin >> x >> y;
        ++a[x];
        ++a[y];
    }
    for (int i = 1; i <= n; i++)
    {
        if (a[i] == 1)
        {
            ++ans;
        }
    }
    cout << ans;
    return 0;
}
